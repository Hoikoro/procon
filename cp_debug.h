template<class T> std::ostream& operator<<(std::ostream &os, const std::vector<T> &v);
template<class T> std::ostream& operator<<(std::ostream &os, const std::deque<T> &d);
template<class F, class S> std::ostream& operator<<(std::ostream &os, const std::pair<F,S> &p);
template<class T> std::ostream& operator<<(std::ostream &os, const std::set<T> &s);
template<class T> std::ostream& operator<<(std::ostream &os, const std::multiset<T> &s);
template<class K,class T> std::ostream& operator<<(std::ostream &os, const std::map<K,T> &m);
template<class K,class T> std::ostream& operator<<(std::ostream &os, const std::multimap<K,T> &m);

//tuple
//modifying http://en.cppreference.com/w/cpp/utility/tuple/tuple
template<class T, std::size_t S>
struct DBGTuple {
    static void debug(std::ostream &os, const T& t){
        DBGTuple<T, S-1>::debug(os,t);
        os << "," << std::get<S-1>(t);
    }
};
template<class T>
struct DBGTuple<T, 1>{
    static void debug(std::ostream &os, const T& t){
        os << std::get<0>(t);
    }
};
template<class... Args>std::ostream& operator<<(std::ostream &os,const std::tuple<Args...>& t){
    os << "(";
    DBGTuple<decltype(t), sizeof...(Args)>::debug(os,t);
    os << ")";
    return os;
}

//debugging output
#define DBG(...) {std::string dst__=#__VA_ARGS__;dbgsplit(dst__);std::stringstream dss__; dss__<<dst__; debug(dss__,__VA_ARGS__);}
void debug(std::stringstream& ds){
    std::cerr<<std::endl;
}
template<class F, class... R>void debug(std::stringstream& ds,const F& f, const R&... r){
    std::string n;
    ds>>n;
    std::cerr<< n <<'='<<f<<' ';
    debug(ds,r...);
}
void dbgsplit(std::string &s){
    int l=s.length(),n=0;
    for(int i=0; i<l; ++i){
        if(s[i]=='(')++n;
        if(s[i]==')')--n;
        if(s[i]==','&&!n)s[i]=' ';
    }
}

//vector
template<class T> std::ostream& operator<<(std::ostream &os, const std::vector<T> &v) {
    os<<"<";
    for(int i=0; i<(int)v.size(); ++i){
        os<<v[i];
        if(i<(int)v.size()-1)os<<",";
    }
    os<<">";
    return os;
}

//deque
template<class T> std::ostream& operator<<(std::ostream &os, const std::deque<T> &d) {
    os<<"<";
    for(int i=0; i<(int)d.size(); ++i){
        os<<d[i];
        if(i<(int)d.size()-1)os<<",";
    }
    os<<">";
    return os;
}
//pair
template<class F, class S> std::ostream& operator<<(std::ostream &os, const std::pair<F,S> &p){
    os<<"(" << p.first << "," << p.second << ")";
    return os;
}

//set
template<class T> std::ostream& operator<<(std::ostream &os, const std::set<T> &s) {
    os<<"{";
    for(auto it = s.begin(); it!=s.end(); it++){
        if(it!=s.begin())os<<",";
        os<<*it;
    }
    os<<"}";
    return os;
}
//multiset
template<class T> std::ostream& operator<<(std::ostream &os, const std::multiset<T> &s) {
    os<<"{";
    for(auto it = s.begin(); it!=s.end(); it++){
        if(it!=s.begin())os<<",";
        os<<*it;
    }
    os<<"}";
    return os;
}
//map
template<class K, class T> std::ostream& operator<<(std::ostream &os, const std::map<K,T> &m) {
    os<<"{";
    for(auto it = m.begin(); it!=m.end(); it++){
        if(it!=m.begin())os<<",";
        os<<*it;
    }
    os<<"}";
    return os;
}
//multimap
template<class K, class T> std::ostream& operator<<(std::ostream &os, const std::multimap<K,T> &m) {
    os<<"{";
    for(auto it = m.begin(); it!=m.end(); it++){
        if(it!=m.begin())os<<",";
        os<<*it;
    }
    os<<"}";
    return os;
}

//vector class for converting operator[] to function at()
template<class T>class dbgvector : public std::vector<T>{
    public:
    dbgvector():std::vector<T>(){};
    explicit dbgvector(int s):std::vector<T>(s){};
    dbgvector(int s,const T& t):std::vector<T>(s,t){};
    template<class It> dbgvector(It f, It l):std::vector<T>(f,l){};
    dbgvector(const vector<T>& v):std::vector<T>(v){};
    dbgvector(vector<T>&& v):std::vector<T>(v){};
    dbgvector(initializer_list<T> il):std::vector<T>(il){};
    T& operator[](int i){return this->at(i);};
    const T& operator[](int i)const{return this->at(i);};
};
#define vector dbgvector
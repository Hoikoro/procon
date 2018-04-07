import networkx as nx
import matplotlib.pyplot as plt
import itertools

s0 = [x for x in itertools.product('abc',repeat = 4) if sum(map(ord,x))%3 == 0]
sub = {'ab':'cc', 'ba':'cc', 'bc':'aa', 'cb':'aa', 'ca':'bb', 'ac':'bb'}
d = {}
for s in s0:
    if s[0] == s[1] or s[1] == s[2] or s[2] == s[3]:
        joined = ''.join(s)
        to = []
        for x in sub:
            to.append(joined.replace(x, sub[x], 1))
        d[joined] = list(set(to)-set([joined]))


Graph = nx.DiGraph(d)
pos = nx.spring_layout(Graph,k = 0.3)
nx.draw_networkx_edges(Graph, pos)
nx.draw_networkx_labels(Graph, pos, font_size=16, font_color="r")

plt.axis("off")
plt.savefig("result.png")
plt.show()


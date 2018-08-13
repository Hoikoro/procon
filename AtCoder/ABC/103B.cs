using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;

namespace B
{
    class Solver
    {
        public bool Solve()
        {
            string s = Console.ReadLine();
            string t = Console.ReadLine();
            for (int i = 0; i < s.Length; i++)
            {
                string tmp = s.Substring(i) + s.Substring(0, i);
                if (tmp == t) return true;
            }
            return false;
        }

    }

    class M
    {
        public static void Main(string[] args)
        {
            if (new Solver().Solve()) { Console.WriteLine("Yes"); }
            else { Console.WriteLine("No"); }
        }

    }
};

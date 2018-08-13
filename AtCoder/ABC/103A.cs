using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;

namespace A
{
    class Solver
    {
        public void Solve()
        {
            int[] a = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            Array.Sort(a);
            Console.WriteLine(a[2] - a[0]);
        }

    }

    class M
    {
        public static void Main(string[] args)
        {
            new Solver().Solve();
        }
    }

};

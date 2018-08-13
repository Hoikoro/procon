using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;

namespace C
{
    class Solver
    {
        public void Solve()
        {
            int n = int.Parse(Console.ReadLine());
            int ans = 0;
            int[] a = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            for (int i = 0; i < n; i++)
            {
                ans += a[i] - 1;
            }
            Console.WriteLine(ans);
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

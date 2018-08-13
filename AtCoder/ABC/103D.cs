using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;

namespace D
{
    class Solver
    {
        public void Solve()
        {
            int[] nm = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            int n = nm[0];
            int m = nm[1];
            var min = new int[n + 1];
            Array.Fill(min, 15 << 26);
            //var min = Enumerable.Repeat(15 << 26, n + 1).ToArray();
            for (int i = 0; i < m; i++)
            {
                int[] ab = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
                min[ab[0]] = Math.Min(min[ab[0]], ab[1]);
            }
            int p = 1, ans = 0;
            for (int i = n - 1; i >= 1; i--)
            {
                min[i] = Math.Min(min[i], min[i + 1]);
            }
            while (p < n && min[p] <= n)
            {
                p = min[p];
                ans++;
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

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {

        static void Main(string[] args)
        {
            int t = int.Parse(Console.ReadLine());
            for(int i = 0; i< t; i++)
            {
                string line = Console.ReadLine();
                string[] parts = line.Split(',');
                int n = int.Parse(parts[0].Trim());
                int b = int.Parse(parts[1].Trim());

                if (n == 0)
                {
                    Console.WriteLine("0");
                    continue;
                }

                Stack<char> result = new Stack<char>();
                while(n > 0)
                {
                    int x = n % b;
                    if (x > 9)
                    {
                        result.Push((char)('A' + (x - 10)));
                    }
                    else
                        result.Push((char)(x + '0'));

                    n /= b;
                }

                while (result.Count > 0)
                    Console.Write(result.Pop());
                Console.WriteLine();
            }
        }
    }
}

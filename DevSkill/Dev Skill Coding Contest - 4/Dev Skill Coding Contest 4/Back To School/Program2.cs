using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication2
{
    class Program
    {
        static void Main(string[] args)
        {
            int t = int.Parse(Console.ReadLine());
            for(int i =0;i<t; i++)
            {
                string line = Console.ReadLine();
                string[] parts = line.Split(' ');
                int cx = int.Parse(parts[0]);
                int cy = int.Parse(parts[1]);
                double r = double.Parse(parts[2]);
                int px = int.Parse(parts[3]);
                int py = int.Parse(parts[4]);

                double result = Math.Sqrt((cx - px) * (cx - px) + (cy - py) * (cy - py));

                if (result == r)
                    Console.WriteLine(String.Format("Case {0}: OnCircle", i+1));
                else if (result < r)
                    Console.WriteLine(String.Format("Case {0}: Inside", i+1));
                else
                    Console.WriteLine(String.Format("Case {0}: Outside", i + 1));
            }
        }
    }
}

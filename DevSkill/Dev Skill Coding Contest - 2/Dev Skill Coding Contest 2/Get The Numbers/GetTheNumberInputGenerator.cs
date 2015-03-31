using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Proggasoft.Utility;

namespace ConsoleApplication2
{
    class GetTheNumberInputGenerator
    {
        #region Debug Region

        #if (DEBUG)
        static FileStream ostrm;
        static StreamWriter writer;
        static TextWriter oldOut = Console.Out;
        static FileStream istrm;
        static StreamReader reader;
        static TextReader oldIn = Console.In;

        static void StartFileWritting()
        {
            try
            {
                ostrm = new FileStream("../../out.txt", FileMode.Create, FileAccess.Write);
                writer = new StreamWriter(ostrm);
            }
            catch (Exception e)
            {
                Console.WriteLine("Cannot open Redirect.txt for writing");
                Console.WriteLine(e.Message);
                return;
            }
            Console.SetOut(writer);
        }

        static void EndFileWritting()
        {
            Console.SetOut(oldOut);
            writer.Close();
            ostrm.Close();
        }

        static void StartFileReading()
        {
            try
            {
                istrm = new FileStream("../../in.txt", FileMode.OpenOrCreate, FileAccess.Read);
                reader = new StreamReader(istrm);
            }
            catch (Exception e)
            {
                Console.WriteLine("Cannot open file for reading");
                Console.WriteLine(e.Message);
                return;
            }
            Console.SetIn(reader);
        }

        static void EndFileReading()
        {
            Console.SetIn(oldIn);
            reader.Close();
            istrm.Close();
        }

        //---------------------------------------------------------

        #endif
        #endregion

        static void Main(string[] args)
        {
            #if (DEBUG)
            StartFileWritting();
            //StartFileReading();
            #endif

            Random rand = new Random();
            Console.WriteLine("10");
            for (int i = 0; i < 10; i++)
            {
                int X = rand.Next(80, 90);
                if (i == 0)
                {
                    Console.WriteLine(X);
                }
                else
                {
                    Console.WriteLine();
                    Console.WriteLine(X);
                }

                List<string> numbers = new List<string>();
                for (int k = 0; k < X; k++)
                {
                    StringBuilder number = new StringBuilder();

                    int numSize = rand.Next(10, 20);
                    for (int j = 0; j < numSize; j++)
                    {
                        number.Append(rand.Next(0, 9));
                    }
                    numbers.Add(number.ToString());
                    Console.WriteLine(number.ToString());
                }
                numbers.Shuffle();

                for (int v = 0; v < X; v++)
                {
                    int t = rand.Next(1, 30);
                    string val = ((t > 15) ? "Success" : "Failed");
                    StringBuilder tt = new StringBuilder(numbers[v]);
                    
                    tt[3] = '*';
                    tt[4] = '*';
                    tt[5] = '*';
                    tt[6] = '*';

                    Console.Write(String.Format("{0},{1}",tt.ToString(), val));
                    Console.WriteLine();
                }
            }

            #if (DEBUG)
            //EndFileReading();
            EndFileWritting();
            #endif
        }
    }
}

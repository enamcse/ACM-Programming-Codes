using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

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
            StartFileReading();
            #endif

            int t = int.Parse(Console.ReadLine());
            for (int i = 0; i < t; i++)
            {
                if (i > 0)
                    Console.ReadLine();
                int x = int.Parse(Console.ReadLine());

                List<string> numbers1 = new List<string>();
                List<KeyValuePair<string, string>> numbers2 = new List<KeyValuePair<string, string>>();
                for (int j = 0; j < x; j++)
                {
                    numbers1.Add(Console.ReadLine());
                }
                for (int j = 0; j < x; j++)
                {
                    string report = Console.ReadLine();
                    string[] reportParts = report.Split(',');

                    numbers2.Add(new KeyValuePair<string, string>(reportParts[0].Trim(), reportParts[1].Trim()));
                }

                Console.WriteLine(String.Format("Case: {0}", i+1));
                Console.WriteLine("Success list");

                PrintSuccessList(numbers1, numbers2);

                Console.WriteLine("Failed list");

                PrintFailedList(numbers1, numbers2);
            }

            #if (DEBUG)
            EndFileReading();
            EndFileWritting();
            #endif
        }

        private static void PrintFailedList(List<string> numbers1, List<KeyValuePair<string, string>> numbers2)
        {
            for (int i = 0; i < numbers2.Count; i++)
            {
                if (numbers2[i].Value == "Failed")
                {
                    string result = null;
                    int count = 0;
                    for (int j = 0; j < numbers1.Count; j++)
                    {
                        if (numbers1[j].StartsWith(numbers2[i].Key.Substring(0, 3)) && numbers1[j].EndsWith(numbers2[i].Key.Substring(7, numbers2[i].Key.Length - 7)))
                        {
                            result = numbers1[j];
                            count++;
                        }
                    }

                    if (count == 1)
                    {
                        Console.WriteLine(String.Format("{0} : {1}", numbers2[i].Key, result));
                    }
                    else
                    {
                        Console.WriteLine(String.Format("{0} : {1}", numbers2[i].Key, "Confused"));
                    }
                }
            }
        }

        private static void PrintSuccessList(List<string> numbers1, List<KeyValuePair<string, string>> numbers2)
        {
            for (int i = 0; i < numbers2.Count; i++)
            {
                if (numbers2[i].Value == "Success")
                {
                    string result = null;
                    int count = 0;
                    for (int j = 0; j < numbers1.Count; j++)
                    {
                        if (numbers1[j].StartsWith(numbers2[i].Key.Substring(0, 3)) && numbers1[j].EndsWith(numbers2[i].Key.Substring(7, numbers2[i].Key.Length - 7)))
                        {
                            result = numbers1[j];
                            count++;
                        }
                    }

                    if (count == 1)
                    {
                        Console.WriteLine(String.Format("{0} : {1}", numbers2[i].Key, result));
                    }
                    else
                    {
                        Console.WriteLine(String.Format("{0} : {1}", numbers2[i].Key, "Confused"));
                    }
                }
            }
        }
    }
}

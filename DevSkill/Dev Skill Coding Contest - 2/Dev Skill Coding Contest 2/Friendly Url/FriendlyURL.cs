using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication2
{
    class FriendlyURL
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
                int m = int.Parse(Console.ReadLine());
                string s = Console.ReadLine();

                int count = 0;
                bool isPrevDash = true;
                StringBuilder result = new StringBuilder();
                for (int j = 0; j < s.Length; j++)
                {
                    if (count == m)
                        break;
                    else if (Char.IsLetterOrDigit(s[j]))
                    {
                        result.Append(Char.ToLower(s[j]));
                        isPrevDash = false;
                        count++;
                    }
                    else if (!isPrevDash)
                    {
                        result.Append('-');
                        isPrevDash = true;
                        count++;
                    }
                }
                Console.WriteLine(result.ToString().Trim('-'));
            }

            #if (DEBUG)
            EndFileReading();
            EndFileWritting();
            #endif
        }
    }
}

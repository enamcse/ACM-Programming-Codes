#define DEBUG
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication2
{
    class ProductOwnersProblem
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

        const int MOD = 1000000007;
        const int MX = 111;
        static int N, M;
        static int[] X = new int[MX];
        static int[] Y = new int[MX]; 
        static int[,] dp = new int[MX,MX];

        static void Main(string[] args)
        {
            #if (DEBUG)
            StartFileWritting();
            StartFileReading();
            #endif

            int T = int.Parse(Console.ReadLine());

            for(int cs = 1 ; cs <= T ; cs++ ){
                ClearArray();
                string line = Console.ReadLine();
                string[] numbers = line.Split(' ');
                N = int.Parse(numbers[0].Trim());
                M = int.Parse(numbers[1].Trim());

                for (int i = 1; i <= M; i++)
                {
                    line = Console.ReadLine();
                    numbers = line.Split(' ');
                    X[i] = int.Parse(numbers[0]);
                    Y[i] = int.Parse(numbers[1]);
                }

                for( int i = X[1] ; i <= Y[1] ; i++ ) dp[1,i] = 1;

                for( int i = 2 ; i <= M ; i++ )
                    for( int j = 0 ; j <= N ; j++ )
                        for( int k = X[i] ; k <= Y[i] ; k++ )
                            if( j - k >= 0 )
                                dp[i,j] = ( dp[i,j] + dp[i-1,j-k] ) % MOD ;

                Console.Write(String.Format("Case {0}: {1}\n", cs, dp[M, N]));
            }

            #if (DEBUG)
            EndFileReading();
            EndFileWritting();
            #endif
        }

        private static void ClearArray()
        {
            for (int i = 0; i < MX; i++)
                for (int j = 0; j < MX; j++)
                    dp[i,j] = 0;
        }
    }
}

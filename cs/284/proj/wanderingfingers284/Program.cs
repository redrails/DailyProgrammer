using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;

namespace swipe
{
    class Program
    {
        static string path = "C:\\Users\\ihtasham.chaudhry\\Documents\\Visual Studio 2015\\Projects\\swipe\\swipe\\words.txt";
        static void Main(string[] args)
        {
            string[] input = { "cghhjkkllooiuytrrdfdftgyuiuytrfdsaazzseertyuioppoiuhgfcxxcfvghujiiuytrfddeews" };

            string[] words = File.ReadAllLines(path);

            var watch = System.Diagnostics.Stopwatch.StartNew();

            foreach (string inp in input)
            {
                var acceptable = reduce(words, inp);
                foreach (int i in acceptable)
                {
                    if (check(words[i], inp))
                    {
                        Debug.WriteLine(words[i]);
                    }
                }
            }
            watch.Stop();
            Console.WriteLine("Run time(ms): " + watch.ElapsedMilliseconds);
            Console.ReadLine();
        }

        static List<int> reduce(string[] list, string input)
        {
            List<int> acceptableList = new List<int>();
            int count = 0;
            foreach(string word in list)
            {
                if (word.Length >= 5 && input[0] == word[0] && input[input.Length - 1] == word[word.Length - 1])
                {
                    acceptableList.Add(count);
                }
                count++;
            }
            return acceptableList;
        }

        static bool check(string word, string input)
        {
            int charcheck = 0;

            foreach (char c in word)
            {
                charcheck = input.IndexOf(c, charcheck);
                if (charcheck == -1)
                {
                    return false;
                }
            }
            return true;
        }
    }
}
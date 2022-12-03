#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string reverse(string s)
{
    // a function that reverses a string
    string sr;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        sr += s[i];
    }
    return sr;
}

int main(int argc, char *argv[])
{
    // get the input from argv including two sequences and options (gap, mismatch, match). ./nw-align AAACCTTGG ACACTGTGG -g -1 -m 1 -d -2 -o alignment.txt
    // default output is standard output if output file is not specified
    string s1 = argv[1];
    string s2 = argv[2];
    int n = s1.length();
    int m = s2.length();

    int gap = -1;
    int match = 1;
    int mismatch = -1;
    string output = "standard output";
    for (int i = 3; i < argc; i++)
    {
        if (string(argv[i]) == "-g")
        {
            gap = stoi(argv[i + 1]);
        }
        else if (string(argv[i]) == "-m")
        {
            match = stoi(argv[i + 1]);
        }
        else if (string(argv[i]) == "-d")
        {
            mismatch = stoi(argv[i + 1]);
        }
        else if (string(argv[i]) == "-o")
        {
            output = argv[i + 1];
        }
    }

    int dp[n + 1][m + 1];
    int tb[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = i*gap;
        tb[i][0] = 1;
    }
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = i*gap;
        tb[0][i] = 2;
    }
    tb[0][0] = 3;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {   
                dp[i][j] = max(dp[i - 1][j - 1] + match, max(dp[i - 1][j] + gap, dp[i][j - 1] + gap));
                if (dp[i][j] == dp[i - 1][j - 1] + match)
                {
                    tb[i][j] = 0;
                }
                else if (dp[i][j] == dp[i - 1][j] + gap)
                {
                    tb[i][j] = 1;
                }
                else
                {
                    tb[i][j] = 2;
                }
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j - 1] + mismatch, max(dp[i - 1][j] + gap, dp[i][j - 1] + gap));
                if (dp[i][j] == dp[i - 1][j - 1] + mismatch)
                {
                    tb[i][j] = 0;
                }
                else if (dp[i][j] == dp[i - 1][j] + gap)
                {
                    tb[i][j] = 1;
                }
                else
                {
                    tb[i][j] = 2;
                }
            }
        }
    }

    int i = n, j = m;
    string s3, s4;
    while (i >= 0 && j >= 0)
    {
        if (tb[i][j] == 0)
        {
            s3 += s1[i - 1];
            s4 += s2[j - 1];
            i--;
            j--;
        }
        else if (tb[i][j] == 1)
        {
            s3 += s1[i - 1];
            s4 += '-';
            i--;
        }
        else if (tb[i][j] == 2)
        {
            s3 += '-';
            s4 += s2[j - 1];
            j--;
        }
        else
        {
            break;
        }
    }

    s3 = reverse(s3);
    s4 = reverse(s4);
    cout << "The Alignment:" << endl;
    cout << s3 << endl;
    cout << s4 << endl;
    cout << "The Alignment score is: " << dp[n][m] << endl;
    
    // if output file is specified, write the alignment to the file
    if (output != "standard output")
    {
        ofstream outfile;
        outfile.open(output);
        outfile << "The Alignment:" << endl;
        outfile << s3 << endl;
        outfile << s4 << endl;
        outfile << "The Alignment score is: " << dp[n][m] << endl;
        outfile.close();
    }
    
    return 0;
}
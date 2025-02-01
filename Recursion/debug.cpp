#include <iostream>
using namespace std;
// 1
bool isPowerOfFour(int n)
{
    if (n <= 0)
    {
        return false;
    }
    if (n == 1)
        return true;
    if (n % 4 != 0)
    {
        return true;
    }
    return isPowerOfFour(n / 4);
}

// 2 unsolved
double myPow(double x, int n)
{
    int p = abs(n);
    double ans = 1.0;
    while (p >= 1)
    {
        if(p%2 == 1){
            ans *= x;
        }
        p /= 2;
        x *= x;
    }
    return n < 0 ? 1/ans : ans;
}

// 3 upsolved
int subset(int input[], int n, int output[][50], int k)
{
    if (n == 0)
    {
        output[0][0] = 0;
        return 1;
    }

    int small = subset(input + 1, n - 1, output, k);
    int count = 0;

    for (int i = 0; i < small; i++)
    {
        output[small + count][1] = input[0];
        int sum = input[0];
        int l = 0;
        for (int j = 2; output[small - count - 1][j - 1] != 0; j++)
        {
            l++;
            output[small + count][j] = output[small - count - 1][j - 1];
            sum = sum + output[small - count - 1][j - 1];
        }
        output[small + count][0] = -1;
        if (sum == k)
        {
            output[small + count][0] = l + 1;
        }
        count++;
    }
    return small + count;
}

int subsetSumToK(int input[], int n, int output[][50], int k)
{
    int temp[1110000][50];
    int size = subset(input, n, temp, k);
    int m = 0;
    for (int i = 0; i < size; i++)
    {
        if (temp[i][0] > 0)
        {
            for (int j = 0; j <= temp[i][0]; j++)
            {
                output[m][j] = temp[i][j];
            }
            m++;
        }
    }

    return m;
}

// 4
int returnPermutations(string input, string output[])
{
    int count = 0;
    string created;
    for (int i = 0; input[i] != '\0' && input.length() > 1; i++)
    {
        char ch = input[i];
        int start = count;
        created = input.substr(0, i) + input.substr(i+1);
        count = count + returnPermutations(created, output + count);
        for (int k = start; k < count; k++)
        {
            output[k] = ch + output[k];
        }
    }
    if (input.length() == 1)
    {
        for (int k = 0; input[k] != '\0'; k++)
        {
            output[count] = output[count] + input[k];
            count++;
        }
    }

    return count;
}

// 5
void removeConsecutiveDuplicates(char *input)
{
    if (input[0] == '\0')
    {
        return;
    }
    if (input[0] == input[1])
    {
        int i = 2;
        for (; input[i] != '\0'; i++)
        {
            input[i - 1] = input[i];
        }
        input[i - 1] = input[i];
        removeConsecutiveDuplicates(input);
    }else{
        removeConsecutiveDuplicates(input+1);
    }
}
/*
Example:
xxab --> xab
*/

// 6
void shift(char input[])
{
    int i = 1;
    for (i = 1; input[i] != '\0'; i++)
        input[i - 1] = input[i];
    input[i - 1] = '\0';
}
void removeX(char input[])
{
    if(input[0] == '\0')
        return;
    if (input[0] == 'x')
    {
        shift(input);
        removeX(input);
    }
    else
        removeX(input + 1);
}
/*
Example:
xxab --> ab
*/

int main()
{
    // 1
    // cout << isPowerOfFour(12) << endl;
    
    // 2
    // cout << myPow(4.00, 2) << endl;

    // 3
    // int input[5] = {1, 2, 3, 4, 5};
    // int n = 5;
    // int output[][50] = {0};
    // int k = 3;
    // int ans = subset(input, n, output, k);
    // cout << ans << endl;

    // 4
    // string input = "racecar";
    // string output[10] = {};
    // int ans =  returnPermutations(input, output);
    // cout << ans << endl;

    // 5
    // char str[] = "xxab";
    // removeConsecutiveDuplicates(str);
    // cout << str << endl;

    // 6
    // char input[] = "xxab";
    // removeX(input);
    // cout << input << endl;

    return 0;
}
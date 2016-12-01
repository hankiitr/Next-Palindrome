#include <bits/stdc++.h>
using namespace std;
#define N 1000000

int all9s (int num[], int n)
{
    int i;
    for(i=0; i<n; ++i)
    {
        if(num[i] != 9)
        return 0;
    }
    return 1;
}

void printArray (int arr[], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}

void nxt_palin1 (int num[], int n)
{
    int mid = n/2;
    bool leftsmall = false;
    int i = mid - 1;
    int j = (n%2)?mid+1:mid;

    while (i>=0 && num[i]==num[j])
    {
        i--;
        j++;
    }
    //cout<<i<<" "<<j;
    if( i<0 || num[i]<num[j])
    {
        leftsmall = true;
    }

    while (i>=0)
    {
        num[j] = num[i];
        j++;
        i--;
    }
    //cout<<i<<" "<<j;
    if(leftsmall == true)
    {
        int carry = 1;
        i = mid-1;
        if(n%2 == 1)
        {
            num[mid] += carry;
            carry = num[mid]/10;
            num[mid] %= 10;
            j = mid + 1;
        }
        else
        j = mid;

        while (i>=0)
        {
            num[i] += carry;
            carry = num[i]/10;
            num[i] %= 10;
            num[j++] = num[i--];
        }
    }
}

void nxt_palin (int num[], int n)
{
    int i;
    if(all9s(num, n))
    {
        printf("1");
        for(i=1; i<n; i++)
        {
            printf("0");
        }
        printf("1");
    }

    else{
         nxt_palin1(num,n);
         printArray(num,n);
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int num[N];
	string s;
	cin>>s;
	int n = s.length();
	for(int i=0; i<n; i++)
	{
	    num[i] = s[i] - 48;
	    //cout<<num[i]<<endl;
    }
	nxt_palin(num, n);
}
return 0;
}

#include<bits/stdc++.h>
using namespace std;
float tinh_gia_tri_trung_binh(vector<int> nums, int k, float tb)
{
    int j;
    float sum = 0;
    for (int i = 0; i <= nums.size() - k; i++)
    {
        j = i;
        while (j < i + k)
        {
            sum += nums[j];
            j++;
        }
        sum = sum / k;
        if (tb < sum)
            tb = sum;
        sum = 0;
    }
    return tb;
}
int main()
{
    // c�ch nh?p m?t d�y s? ko bt trc dc s? pt? ta d�ng chu?i k� t? v� chuy?n d?i t? k� t? sang s? nguy�n
    string input;
    getline(cin, input);
    // h�m stringstream ss() d�ng d? t�ch c�c k� t? s? nguy�n t? chu?i k� t? th�nh s? nguy�n
    stringstream ss(input);
    vector<int> nums;
    int number;
    // ss>>number : th�m ph?n t? dc t�ch v�o number n?u c� ptu th� th?c hi?n n�m.pusk_back(number);
    while (ss >> number)
        nums.push_back(number);
    int k;
    cin >> k;
    float tb = 0;
    cout << fixed << setprecision(5) << tinh_gia_tri_trung_binh(nums, k, tb);
    return 0;
}

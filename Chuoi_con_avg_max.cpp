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
    // cách nh?p m?t dãy s? ko bt trc dc s? pt? ta dùng chu?i kı t? và chuy?n d?i t? kı t? sang s? nguyên
    string input;
    getline(cin, input);
    // hàm stringstream ss() dùng d? tách các kı t? s? nguyên t? chu?i kı t? thành s? nguyên
    stringstream ss(input);
    vector<int> nums;
    int number;
    // ss>>number : thêm ph?n t? dc tách vào number n?u có ptu thì th?c hi?n núm.pusk_back(number);
    while (ss >> number)
        nums.push_back(number);
    int k;
    cin >> k;
    float tb = 0;
    cout << fixed << setprecision(5) << tinh_gia_tri_trung_binh(nums, k, tb);
    return 0;
}

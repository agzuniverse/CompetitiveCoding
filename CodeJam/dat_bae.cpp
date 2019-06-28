/*
Interactive problem:
There are N machine of which B are broken. Each machine stores one bit
and sends them back. We can make upto F queries.

For each query we send N bits which are stored in the machines (index 0 based)
Then the bits are read back and given to us. The broken machines don't return anything
Which means we get back N-B bits.

Identify and print the indices of the broken machines.

Constrant: B<(min(15,N-1))
There will be T testcases.
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, b, f;
    string bin_to_str;
    cin >> t;
    for (int z = 0; z < t; z++)
    {
        cin >> n >> b >> f;
        deque<string> inputs, outputs, outputs_temp;
        inputs.resize(n);
        for (int i = 0; i < 16; i++)
        {
            bin_to_str = bitset<4>(i).to_string();
            for (int j = i; j < n; j += 16)
                inputs[j] = bin_to_str;
        }

        string input_str = "", output_str;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < n; j++)
                input_str += inputs[j][i];
            cout << input_str << endl;
            cin >> output_str;
            outputs_temp.push_back(output_str);
            input_str = "";
        }
        string output_final = "";
        for (int i = 0; i < n - b; i++)
        {
            for (int j = 0; j < 4; j++)
                output_final += outputs_temp[j][i];
            outputs.push_back(output_final);
        }

        vector<int> missing_indices;
        int counter = 0;

        while (outputs.size() != 0)
        {
            while (outputs[0] != inputs[0])
            {
                inputs.pop_front();
                missing_indices.push_back(counter);
                counter++;
            }
            inputs.pop_front();
            outputs.pop_front();
            counter++;
        }
        for (auto i : missing_indices)
            cout << i << " ";
    }
}
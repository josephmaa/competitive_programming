#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    string time;
    int repeat;

    string delimiter = ":";
    int split;

    vector<string> times;
    vector<int> repeats;

    // Input times.
    for (int i = 0; i < t; i++)
    {
        cin >> time >> repeat;
        split = time.find(delimiter);

        // Even indices are the hours, odd indices are the minutes.
        times.push_back(time.substr(0, split));
        times.push_back(time.substr(time.find(delimiter) + 1, time.size()));
        repeats.push_back(repeat);
    }

    // Output times.
    for (int i = 0; i < t; i++)
    {
        repeat = repeats[i];
        int delta_hour = repeat / 60;
        int delta_minute = repeat % 60;

        int seen_first = 0;
        int res = 0;
        string start_hour = times[i * 2];
        string start_minute = times[i * 2 + 1];

        while (not seen_first or start_hour != times[i * 2] or start_minute != times[i * 2 + 1])
        {
            if (not seen_first)
            {
                seen_first = 1;
            }

            if (times[i * 2].size() == times[i * 2 + 1].size() and (equal(times[i * 2].begin(), times[i * 2].end(), times[i * 2 + 1].rbegin())))
            {
                res += 1;
            }

            int cur_hour = stoi(times[i * 2]);
            int cur_minute = stoi(times[i * 2 + 1]);

            cur_hour += delta_hour;
            cur_minute += delta_minute;

            if (cur_minute >= 60)
            {
                cur_hour += 1;
                cur_minute = cur_minute % 60;
            }

            if (cur_hour >= 24)
            {
                cur_hour = cur_hour % 24;
            }

            // Format the strings.
            times[i * 2] = string(2 - min(2, (int)to_string(cur_hour).length()), '0') + to_string(cur_hour);
            times[i * 2 + 1] = string(2 - min(2, (int)to_string(cur_minute).length()), '0') + to_string(cur_minute);
        }
        cout << res << endl;
    }
}
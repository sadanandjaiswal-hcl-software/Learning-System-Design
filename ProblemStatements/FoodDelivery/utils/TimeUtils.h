#ifndef TIME_UTILS_H
#define TIME_UTILS_H

#include <bits/stdc++.h>
using namespace std;

class TimeUtils {
    public:
        static string getCurrentTime() {
            time_t now = time(0);
            char buf[80];
            strftime(buf, sizeof(buf), "%Y-%m-%d %X", localtime(&now));
            return string(buf);
        }
};

#endif
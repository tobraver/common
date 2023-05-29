#include <iostream>
#include <thread>
#include <chrono>

#include <sys/time.h>

#define HOUR_OF_DAY (24)

#define MIN_OF_HOUR (60)
#define MIN_OF_DAY  (MIN_OF_HOUR * HOUR_OF_DAY)

#define SEC_OF_MIN  (60)
#define SEC_OF_HOUR (SEC_OF_MIN * MIN_OF_HOUR)
#define SEC_OF_DAY  (SEC_OF_MIN * MIN_OF_DAY)

#define MS_OF_SEC   (1000)
#define MS_OF_MIN   (MS_OF_SEC * SEC_OF_MIN)
#define MS_OF_HOUR  (MS_OF_SEC * SEC_OF_HOUR)
#define MS_OF_DAY   (MS_OF_SEC * SEC_OF_DAY)

#define MONTH_OF_YEAR (12)

#define US_SLEEP(_t) (std::this_thread::sleep_for(std::chrono::microseconds(_t)))
#define MS_SLEEP(_t) (std::this_thread::sleep_for(std::chrono::milliseconds(_t)))

#define COMMON_TIME_API  inline

namespace common
{
    namespace m_time
    {
        COMMON_TIME_API void delay_us(int64_t nus)
        {
            std::this_thread::sleep_for(std::chrono::microseconds(nus));
        }

        COMMON_TIME_API void delay_ms(int64_t nms)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(nms));
        }

        COMMON_TIME_API void delay(int64_t nsec)
        {
            std::this_thread::sleep_for(std::chrono::seconds(nsec));
        }

        COMMON_TIME_API uint64_t get_ticks(void)
        {
            struct timespec current_time;
            clock_gettime(CLOCK_MONOTONIC, &current_time);
            return (uint64_t)((current_time.tv_sec * 1000) + (current_time.tv_nsec / 1000000)); // ms
        }

        COMMON_TIME_API int64_t get_curr_time(void)
        {
            struct timeval tv;
            gettimeofday(&tv, NULL);
            return (int64_t)(tv.tv_sec * 1000 + tv.tv_usec / 1000); // ms
        }
        
        COMMON_TIME_API int64_t get_curr_timestamp(void)
        {
            return get_curr_time() / 1000; // sec
        }
        
        // year month day
        COMMON_TIME_API std::string get_ymd(time_t timestamp)
        {
            struct tm *t = localtime(&timestamp);
            char st[20] = {0};
            snprintf(st, sizeof(st), "%02d-%02d-%02d", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);
            return std::string(st);

        }
        
        COMMON_TIME_API std::string get_curr_ymd(void)
        {
            time_t timestamp = time(NULL);
            return get_ymd(timestamp);
        }
        
        // hour minutes seconed
        COMMON_TIME_API std::string get_hms(time_t timestamp)
        {
            struct tm *t = localtime(&timestamp);
            char st[20] = {0};
            snprintf(st, sizeof(st), "%02d:%02d:%02d", t->tm_hour, t->tm_min, t->tm_sec);
            return std::string(st);

        }
        
        COMMON_TIME_API std::string get_curr_hms(void)
        {
            time_t timestamp = time(NULL);
            return get_hms(timestamp);
        }

        // year month day + hour minutes seconed
        COMMON_TIME_API std::string get_ymd_hms(time_t timestamp)
        {
            struct tm *t = localtime(&timestamp);
            char st[30] = {0};
            snprintf(st, sizeof(st),"%04d-%02d-%02d %02d:%02d:%02d", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
            return std::string(st);

        }
        
        COMMON_TIME_API std::string get_curr_ymd_hms(void)
        {
            time_t timestamp = time(NULL);
            return get_ymd_hms(timestamp);
        }
    }
}





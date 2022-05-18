#include "stats.h"

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    s.average = 0;
    s.min = 0;
    s.max = 0;
    s.min =*numberset;
    for(int i=0;i<setlength;i++)
    {
       if(s.min>*(numberset+i))
       s.min=*(numberset+i);
    }
    s.max=*numberset;
    for(int i=0;i<setlength;i++)
    {
       if(s.max<*(numberset+i))
       s.max=*(numberset+i);
    }
    for(int i=0;i<setlength;i++)
    s.average+=*(numberset+i);
    s.average/=setlength;
    return s;
}

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;
void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
   if(computedStats.max>maxThreshold)
   {
          alerters[0]();
          alerters[1]();
   }
}
void emailAlerter()
{
    emailAlertCallCount++;
}
void ledAlerter()
{
    ledAlertCallCount++;
}

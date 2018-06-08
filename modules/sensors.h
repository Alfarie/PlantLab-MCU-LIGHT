#include <Task.h>
extern TaskManager taskManager;

#include "./light.h"

class Sensors : public Task
{
  public:
    static Sensors *s_instance;
    Sensors() : Task(MsToTaskTime(1000))
    {
        taskManager.StartTask(Light::instance());
    }
    static Sensors *instance()
    {
        if (!s_instance)
            s_instance = new Sensors;
        return s_instance;
    }

  private:
    String cmd = "";
    virtual bool OnStart()
    {
        return true;
    }
    virtual void OnUpdate(uint32_t delta_time)
    {
        cmd = "{" + String (Light::instance()->GetLight() )   + "}";
        Serial.println(cmd);
    }
};

Sensors *Sensors::s_instance = 0;
#include "BaseEngine.h"


class DemoAMain : public BaseEngine
{
    public:
        DemoAMain();
        ~DemoAMain();
        void SetupBackgroundBuffer(void);
        int InitialiseObjects(void);
        void DrawStrings();
        //void MouseDown(int iButton, int iX, int iY);
    protected:
    private:
};

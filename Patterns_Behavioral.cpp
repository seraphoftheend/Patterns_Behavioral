#include <iostream>
#include "Mediator.h"
#include "Strategy.h"
#include "TemplateMethod.h"
#include "State.h"
#include "Chain of Responsibility.h"

int main()
{
    //------------------------------------------------------------------------------------------

    //------------------------------- Mediator ------------------------------------------------
   /* ADC* adc = new ADC;
    AnalogTemperatureSensor* ats = new AnalogTemperatureSensor;
    Indicators* ind = new Indicators;
    Mediator* med = new ConcreteMediator(adc, ats, ind);

    adc->doMeasurement();*/
    
    //------------------------------------------------------------------------------------------

    //------------------------------- Strategy ------------------------------------------------

    /*Context* context = new Context(new NormalSettings);
    context->chooseSettings();
    cout << endl;

    context->set_strategy(new HighSettings);
    context->chooseSettings();
    cout << endl;

    context->set_strategy(new UltraSettings);
    context->chooseSettings();

    delete context;*/

    //------------------------------------------------------------------------------------------

    //------------------------------- TemplateMethod ------------------------------------------------

    /*cout << "Budget PC configuration" << endl;
    BudgetPC* budgetPC = new BudgetPC;
    ClientCode(budgetPC);
    cout << endl << endl;
    cout << "Advanced PC configuration:" << endl;
    AdvancedPC* advancedPC = new AdvancedPC;
    ClientCode(advancedPC);
    delete budgetPC;
    delete advancedPC;*/

    //------------------------------------------------------------------------------------------

    //------------------------------- State ------------------------------------------------

    /*AlertStateContext* context = new AlertStateContext(new SilentMode);
    context->Notification();
    cout << endl;

    context->TransitionTo(new NormalMode);
    context->Notification();
    delete context;*/

    //------------------------------------------------------------------------------------------

    //------------------------------- Chain of responsibility ------------------------------------------------

    Picture* p = new Picture("IMG_20200616_165439");
    processPicture(*p);

    return 0;
}


#ifndef STATE_H
#define STATE_H

class State{

    public:
        State();
        State(const State& orig);

        void setCountryChange();
        void setMoneyChange();

        void showState();

    private:
        bool countryChange;
        bool moneyChange;

};
#endif
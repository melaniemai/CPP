#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <stack>
#include <ctime>
#include <queue>

using namespace std;
    class Passenger {
    private:
        int arrivalTime, originFloor, destination, exitTime, waitTime, direction, IDNum;

        bool onElevator;

    public:
        Passenger();
        Passenger(int ID, int aT, int oF, int dF);
        int getArrivalTime();                       // time passenger arrived
        int getOriginFloor();
        int getTravelTime();						//exitTime-arrivalTime+waitTime
        int getDestination();                       // floor passenger wants to go to
        int getExitTime();                          // time passenger gets off elevator
        int getWaitTime();
        int getIDNum();                             // tells which passenger number is which
        int getDirection();                         // going up or down
        bool getOnElevator();
        void setOnElevator();						// onElevator set true
        void setExitTime(int et);
        void setWaitTime(int t);
//		operator = (const Passenger& P1);
        int  copyPassenger(Passenger copyFrom);
    };

    Passenger::Passenger(){
        arrivalTime = 0;
        originFloor = 0;
        destination = 0;
        exitTime = 0;
        waitTime =  0;
        direction = 0;
        IDNum = 0;
        onElevator = false;
    }

    Passenger::Passenger(int ID, int aT, int oF, int dF){
        arrivalTime = aT;
        onElevator = false;
        waitTime = 0;
        exitTime = aT;
        originFloor = oF;
        destination = dF;
        if (destination > originFloor){
            direction = 1;
        }

        IDNum = ID;
    }

    int  Passenger::copyPassenger(Passenger copyFrom){
        this->arrivalTime = copyFrom.getArrivalTime();
        this->originFloor = copyFrom.getOriginFloor();
        this->destination = copyFrom.getDestination();
        this->exitTime = copyFrom.getExitTime();
        this->waitTime =  copyFrom.getWaitTime();
        this->direction = copyFrom.getDirection();
        this->IDNum = copyFrom.getIDNum();
        this->onElevator = copyFrom.getOnElevator();
        return 0;
    }
/*	Passenger::operator = (const Passenger& P1){
        this->arrivalTime = P1.getArrivalTime();
        this->originFloor = P1.getOriginFloor();
        this->destination = P1.getDestination();
        this->exitTime = P1.getExitTime();
        this->waitTime =  P1.getWaitTime();
        this->direction = P1.getDirection();
        this->IDNum = P1.getIDNum();
        this->onElevator = P1.getOnElevator();
        return 0;
    } */

    int Passenger::getArrivalTime(){
        return arrivalTime;
    }


    int Passenger::getOriginFloor(){
        return originFloor;
    }

    int Passenger::getDestination(){
        return destination;
    }

    int Passenger::getExitTime(){
        return exitTime;
    }
    int Passenger::getWaitTime(){
        return waitTime;
    }
    bool Passenger::getOnElevator(){
        return onElevator;
    }

    int Passenger::getTravelTime(){
        int travelTime = exitTime - arrivalTime + waitTime;
        return travelTime;
    }



    int Passenger::getIDNum(){
        return IDNum;
    }

    int Passenger::getDirection(){
        if(originFloor < destination){             // since originFloor is less, indicates elevator moving up
            direction = 1;
            return 1;
        } else{
            direction = 0;
            return 0;
        }
    }

    void Passenger::setOnElevator(){
        onElevator = true;
    }

    void Passenger::setExitTime(int eT){
        exitTime = eT;
    }
    void Passenger::setWaitTime(int t){
        waitTime = t - arrivalTime;
    }


class stateEvent{
    private:
        int time; // state will need to change when clock reaches this time
        int newState; // new state when clock reaches time
    public:
        stateEvent();
        stateEvent(int t, int s);
        int getTime();
        int getState();
        void setState(int s);
        void setTime(int t);
};

    stateEvent::stateEvent(){
        time = 0;
        newState = 0;
    }

    stateEvent::stateEvent(int t, int s){
        time = t;
        newState = s;
    }

    int stateEvent::getTime(){
        return time;
    }

    int stateEvent::getState(){
        return newState;
    }

    void stateEvent::setState(int s){
     newState = s;
    }

    void stateEvent::setTime(int t){
     time = t;
    }

class Compare
{
public:
    bool operator() (stateEvent& s1, stateEvent& s2)
    const {
        return (s1.getTime() > s2.getTime());
    }
};

class HBtn{
    public:
    bool upBtn;
    bool dnBtn;
    HBtn();
};

HBtn::HBtn(){
    upBtn = false;
    dnBtn = false;
}

class Elevator {
    private:
        vector<Passenger> ePassengers;                  // vector of passengers in elevator
        int floorServed;                                // last floor served by elevator
        int currentFloor;								// current floor
        int destFloor;									// destination floor
        int eNum;                                       // distinguishes elevator numbers
        int state;										// state of elevator - 1-5 are valid states
        int tripCounter;								// trip counter
        int direction;									// up - 1; down - 0;
        vector<bool> cBtn;								// which buttons pressed in the elevator
        priority_queue <stateEvent, vector<stateEvent>, Compare> *eventQueue;					// state transitions scheduled in a min_heap
        bool doorOpen;									// state of door
    public:
        Elevator();
        Elevator(int ID, int f);
        vector<Passenger> getElevPass();
        int getFloorServed();
        int getElevatorNumber();
        int getState();
        void setFloorServed(int f);
        void setElevatorNumber(int n);
        void setState(int s);
        void load(int t, queue<Passenger> pQ);                    // loads passenger(s) onto elevator
        queue<Passenger> unload(int f, int t);                         // takes passenger out

        queue<Passenger> transitionState(int t, vector<HBtn> h, vector<queue<Passenger>> pOnFloors, vector<Elevator> allElevators);
    };

    Elevator::Elevator(){

    }

    Elevator::Elevator(int ID, int f){
        eNum = ID; // elevator id
        floorServed = 0; //lowest floor
        currentFloor = 0;
        destFloor = 0;
        state = 1; //idle
        tripCounter = 0;
        direction = 1; //up
        for (int i = 0; i < f; i++){
            cBtn.push_back(false);
        }
        doorOpen = false; // keep it closed unless requested by passenger
    }

    int Elevator::getFloorServed(){
        return floorServed;
    }

    int Elevator::getElevatorNumber(){
        return eNum;
    }

    int Elevator::getState(){
        return state;
    }
    vector<Passenger> Elevator::getElevPass(){
        return ePassengers;
    }


    void Elevator::setFloorServed(int f){
        floorServed = f;
    }

    void Elevator::setElevatorNumber(int n){
        eNum = n;
    }

    void Elevator::setState(int s){
        state = s;
    }

    void Elevator::load(int t, queue<Passenger> pQ){
        int i;
        Passenger p;
        //add waiting passengers to elevator
        // press buttons for passenger's destination floor
        //set their time - wait time on floor and time to get on elevator
        for (i=0; i < pQ.size(); i++){
            p.copyPassenger(pQ.front());
            p.setOnElevator();
            p.setWaitTime(t);
            pQ.pop();
            cBtn[p.getDestination()] = true;
            ePassengers.push_back(p);
        }
        // set direction

        //increment trip counter if direction changed

    }

    queue<Passenger> Elevator::unload(int cf, int t){
        queue<Passenger> exitors;
        Passenger p;
        for(int i = 0; i < ePassengers.size(); i++){
            if(ePassengers[i].getDestination() == cf){              // checks all passengers in elevator if it's their destination
                p.copyPassenger(ePassengers[i]);
                p.setExitTime(t);
                ePassengers.erase(ePassengers.begin() + i);
                cout << "EXITING: Passenger " << p.getIDNum() << " on floor " << cf << "." << endl;
                exitors.push(p);
            }
        }
        return exitors;
    }

    queue<Passenger> Elevator::transitionState(int t, vector<HBtn> h, vector<queue<Passenger>> pOnFloors, vector<Elevator> allElevators){
    //	cout << "Entering elevator transition" << endl;
        // are there any events for time t?
        queue<Passenger> qP;
        int newState;
        stateEvent s = eventQueue->top();
        stateEvent scheduledEvent;

        int i;
        bool hButtonPressed = false; // hallway button pressed
        bool eButtonPressed = false; // elevator button pressed
        for (i = 0; i < h.size(); i++){
            if (h[i].upBtn != false || h[i].dnBtn != false){
                hButtonPressed = true;
            }
        }
        for (i = 0; i < cBtn.size(); i++){
            if (cBtn[i]=true) {
                eButtonPressed = true;
            }
        }

        // code to check timer events
        if (s.getTime() == t){
            newState = s.getState();
            if (state != newState){
                state = newState;
                switch (newState){
                    case 1: //idle/wait
                    //check hallway & elevator buttons
                        if (hButtonPressed){
                            //hallway button pressed
                            doorOpen = true;//open door
                            this->load(t, pOnFloors[currentFloor]);	//load  passenegrs
                            doorOpen = false; // close door
                        }
                        if (eButtonPressed){
                            //elevator button pressed
                            //determine button pressed for which floors and determine direction
                            // determine if button pressed on a floor above
                            bool setDirection = false;
                            bool setDestFloor = false;
                            cBtn[currentFloor] = false;
                            i = currentFloor+1;
                            while (i > cBtn.size() && !setDirection && !setDestFloor){
                                if (cBtn[i]==true) {
                                    if (!setDestFloor) {
                                        destFloor = i;
                                        setDestFloor = true;
                                    }
                                    direction = 1; // going up
                                    h[currentFloor].upBtn = false;
                                    setDirection = true;
                                }
                                i++;
                            }
                            if (!setDirection){
                                i = currentFloor-1;
                                while (i >= 0 && !setDirection && !setDestFloor){

                                    if (cBtn[i]==true) {
                                        if (!setDestFloor) {
                                            destFloor = i;
                                            setDestFloor = true;
                                        }
                                        direction = 0; // going down
                                        h[currentFloor].dnBtn = false;
                                        setDirection = true;
                                    }
                                    i--;
                                }
                            }
                        }
                        tripCounter++; // increment trip counter
                        // schedule next state in 2 seconds
                        scheduledEvent.setState(2); // next state # is 2
                        scheduledEvent.setTime(t+2); // it is scheduled for 2 seconds later when it should stop accelerating
                        eventQueue->push(scheduledEvent); // add to min heap

                        break;
                    case 2:
                        //acceleration over; starting constant motion
                        //schedule next state transacation after 3 seconds - end of constant motion
                        scheduledEvent.setState(3); // next state # is 3
                        scheduledEvent.setTime(t+3); // it is scheduled for 3 seconds later when it should stop accelerating
                        eventQueue->push(scheduledEvent); // add to min heap

                        break;
                    case 3:
                        //constant motion over
                        //check if we need to stop at next floor; if so decelerate;
                        // check if buttons pressed while this elevator was moving and if we need to stop sooner than destination floor
                        if (direction == 0){
                            i = currentFloor-1;
                            while (i > destFloor){

                                if ( h[i].dnBtn != false){
                                    destFloor = i;
                                }
                                i--;
                            }
                        }
                        else{
                            i = currentFloor+1;
                            while (i < destFloor){
                                if ( h[i].upBtn != false){
                                    destFloor = i;
                                }
                                i++;
                            }
                        }

                        if ((destFloor - currentFloor == 1) || (destFloor - currentFloor == -1)){
                            scheduledEvent.setState(5); // next state # is 5
                            scheduledEvent.setTime(t+2); // it is scheduled for 2 seconds later when it should stop deaccelerating
                            eventQueue->push(scheduledEvent); // add to min heap
                        }
                        else{
                            scheduledEvent.setState(4); // next state # is 4
                            scheduledEvent.setTime(t+5); // it is scheduled for 5 seconds later when it should stop constant motion
                            eventQueue->push(scheduledEvent); // add to min heap
                            if (direction = 0){
                                currentFloor--; // change current floor
                            }
                            else{
                                currentFloor++; // change current floor
                            }
                        }

                        break;
                    case 4:
                        //it has moved one floor
                        //now needs to check if it needs to deaccelerate or keep moving
                        // check if buttons pressed while this elevator was moving and if we need to stop sooner than destination floor
                        if (direction == 0){
                            i = currentFloor-1;
                            while (i > destFloor){

                                if ( h[i].dnBtn != false){
                                    destFloor = i;
                                }
                                i--;
                            }
                        }
                        else{
                            // it is moving up
                            i = currentFloor+1;
                            while (i < destFloor){
                                if ( h[i].upBtn != false){
                                    destFloor = i;
                                }
                                i++;
                            }
                        }

                        if ((destFloor - currentFloor == 1) || (destFloor - currentFloor == -1)){
                            scheduledEvent.setState(5); // next state # is 5
                            scheduledEvent.setTime(t+2); // it is scheduled for 2 seconds later when it should stop deaccelerating
                            eventQueue->push(scheduledEvent); // add to min heap
                        }
                        else{
                            // keep going
                            scheduledEvent.setState(4); // next state # is 4
                            scheduledEvent.setTime(t+5); // it is scheduled for 5 seconds later when it should stop constant motion
                            eventQueue->push(scheduledEvent); // add to min heap
                            if (direction == 0){
                                currentFloor--; // change current floor
                            }
                            else{
                                currentFloor++; // change current floor
                            }
                        }

                        break;
                    case 5:
                        // stop deaccelerating;

                         // change current floor to dest floor
                         currentFloor = destFloor;
                        // reset elevator button for this floor
                        cBtn[currentFloor] = false;
                        //hallway button reset
                        if (direction = 0){
                            h[currentFloor].dnBtn = false;
                        }
                        else{
                            h[currentFloor].upBtn = false;
                        }
                        //open door
                        doorOpen = true;
                        // unload passengers
                        qP = this->unload(currentFloor, t);
                        // load passengers if any on this floor
                        if (pOnFloors[currentFloor].size()>0){
                            this->load(t, pOnFloors[currentFloor]);	//load  passenegrs
                            doorOpen = false; // close door
                        }

                        // are there still buttons pressed in elevator in the same direction; if so set new destination floor
                        bool setDestFloor = false;
                        if (direction == 0){
                            i = currentFloor-1;
                            while (!setDestFloor){

                                if ( cBtn[i] != false){
                                    destFloor = i;
                                    setDestFloor = true;
                                }
                                i--;
                            }
                        }
                        else{
                            // it is moving up
                            i = currentFloor+1;
                            while (!setDestFloor){
                                if ( cBtn[i] != false){
                                    destFloor = i;
                                    setDestFloor = true;
                                }
                                i++;
                            }
                        }
                        // are there hallway buttons pressed in same direction
                        bool foundHallwayBtn = false;
                        if (direction == 0 && destFloor != currentFloor){
                            i = currentFloor-1;
                            while (i > destFloor && !foundHallwayBtn){

                                if ( h[i].dnBtn != false){
                                    if (destFloor < i){
                                        destFloor = i;
                                        foundHallwayBtn = true;
                                    }

                                }
                                i--;
                            }
                        }
                        else{
                            // it is moving up
                            if (destFloor != currentFloor){
                                i = currentFloor+1;
                                while (i < destFloor && !foundHallwayBtn){
                                    if ( h[i].upBtn != false){
                                        if (destFloor > i){
                                            destFloor = i;
                                            foundHallwayBtn = true;
                                        }
                                    }
                                    i++;
                                }
                        }
                        // else if there are buttons pressed in opposite direction, reset direction and destFloor,

                        // are there still buttons pressed in elevator in the opp direction; if so set new destination floor
                        if (destFloor == currentFloor){
                            setDestFloor = false;
                            if (direction == 0){
                                i = currentFloor+1;
                                while (!setDestFloor){

                                    if ( cBtn[i] != false){
                                        destFloor = i;
                                        direction = 1;
                                        setDestFloor = true;
                                    }
                                i++;
                                }
                            }

                            else{
                            // it is moving up
                            i = currentFloor-1;
                                while (!setDestFloor){
                                    if ( cBtn[i] != false){
                                        destFloor = i;
                                        direction =  0;
                                        setDestFloor = true;
                                    }
                                    i--;
                                }
                            }

                        // are there hallway buttons pressed in opp direction
                            bool foundHallwayBtn = false;
                            if (direction == 0 && destFloor == currentFloor){
                                i = currentFloor+1;
                                while (!foundHallwayBtn){

                                    if ( h[i].dnBtn != false){
                                        destFloor = i;
                                        direction = 1;
                                        foundHallwayBtn = true;
                                    }


                                i--;
                                }
                            }
                        else{
                            // it is moving up
                            if (direction == 1 && destFloor == currentFloor){
                                i = currentFloor-1;
                                while (!foundHallwayBtn){
                                    if ( h[i].upBtn != false){
                                        destFloor = i;
                                        direction  = 0;
                                        foundHallwayBtn = true;
                                    }
                                    i++;
                                }
                            }
                        }
                        // set new destination floor and schedule acceeration , set state to 2 after 2 secs
                        if (destFloor != currentFloor){
                            scheduledEvent.setState(2); // next state # is 2
                            scheduledEvent.setTime(t+2); // it is scheduled for 2 seconds later when it should stop accelerating
                            eventQueue->push(scheduledEvent); // add to min heap
                        }
                        // if no buttons pressed and no passenegrs, move to state 1
                        else {
                            scheduledEvent.setState(1); // next state # is 1
                            scheduledEvent.setTime(t+1); // it is scheduled for 1 seconds later when it should check again
                            eventQueue->push(scheduledEvent); // add to min heap
                        }
                        break;
                        }
                    }
                }


            return qP;
            }
        }
    }



class Building
{
    private:
        int elevators, floors;
        vector<Elevator> allElevators;                  // vector to hold all the elevators
        vector<queue<Passenger>> allFloors;           	// vector to hold all the floors and each floor has a queue of passengers
        vector<queue<Passenger>> upServiceCall;
        vector<queue<Passenger>> dnServiceCall;
        vector<HBtn> allHBtn;							// vector to hold hallway buttons
        stack<Passenger> exitors;									// exiting passengers

    public:
        Building(int elNum, int flNum);
        void addHallwayPassenger(int pID, int tOR, int oF, int dF);
        void transitionState(int time);
        void printStats();
};

    Building::Building(int elNum, int flNum){
        elevators = elNum;
        floors = flNum;

        for(int i = 0; i < elevators; i++){             // creates elevator
            Elevator elev(i, floors);                   // assigns elevator number
            allElevators.push_back(elev);               // pushes into elevator vector to store
        }

        for(int i = 0; i < floors; i++){                // creates how ever many floors in building
            queue<Passenger> passengerGroup;
            allFloors.push_back(passengerGroup);        // puts a queue of passengers in each index of the floor vector
            queue<Passenger> upPG;
            upServiceCall.push_back(upPG);
            queue<Passenger> dnPG;
            dnServiceCall.push_back(dnPG);
            HBtn hallwayBtn;
            allHBtn.push_back(hallwayBtn);
        }
    }

    void Building::addHallwayPassenger(int pID, int tOR, int oF, int dF){
        Passenger p(pID, tOR, oF, dF);
        allFloors[oF].push(p);
        if (oF > dF){
            dnServiceCall[oF].push(p);
            allHBtn[oF].dnBtn = true;
        }
        else{
            upServiceCall[oF].push(p);
            allHBtn[oF].upBtn = true;
        }
    }

    void Building::transitionState(int time){
        vector<queue<Passenger>> exitingP;
        Passenger p;
        //change state of each elevator if needed
        //add any exiting pasengers to exitors stack
    //	cout << "Entering building transition state" << endl;
        for (int i = 0; i < elevators; i++){
    //		cout << "elevators " << elevators << endl;
    //		cout << "Processing elevator " << i << endl;
            exitingP.push_back(allElevators[i].transitionState(time, allHBtn, allFloors, allElevators));
        //	cout << "completed elevator transition" << endl;
        }

        for (int j = 0; j<exitingP.size(); j++){
        //	cout << " size of exitingP vector " << exitingP.size() << endl;
            p.copyPassenger(exitingP[j].front());
            exitingP[j].pop();
            exitors.push(p);
        }
    //	cout << "exiting building transition state" << endl;
    }

    void Building::printStats(){
        int totalTravelTime = 0;
        int maxTravelTime = 0;
        int totalWaitTime = 0;
        int maxWaitTime = 0;
        Passenger p;

        int numOfPassengers = exitors.size();
        cout << "Numbers of Passengers Served = " << numOfPassengers << endl;
        int result;
        cout << "Number of Passenegrs Served: " << numOfPassengers << endl;
        for (int i = 0; i < numOfPassengers; i++){

            result = p.copyPassenger(exitors.top());
            totalTravelTime = totalTravelTime + p.getTravelTime();
            totalWaitTime = totalWaitTime + p.getWaitTime();
            if  (p.getTravelTime() > maxTravelTime){
                maxTravelTime = p.getTravelTime();
            }
            if  (p.getWaitTime() > maxWaitTime){
                maxWaitTime = p.getWaitTime();
            }
            exitors.pop();
        }
        cout << "Average Wait Time: " << (double)totalWaitTime/numOfPassengers << endl;
        cout << "Maximum Wait  Time: " << maxWaitTime << endl;
        cout << "Average Total Travel Time: " << (double)totalTravelTime/numOfPassengers << endl;
        cout << "Maximum Travel Time: " << maxTravelTime << endl;
    }

int main()
{
    //Create building with user defined floors and elevators
    int numOfFloors = 0;
    int numOfElev = 0;
    bool enteredCorrectly = false;

    while (!enteredCorrectly){
        if (numOfFloors > 0 && numOfFloors <=10){
            enteredCorrectly = true;
        }
        else{
            cout << "Enter # of floors (1-10)" << endl;
            cin >> numOfFloors;
        }
    }

    enteredCorrectly = false;
    while (!enteredCorrectly){
        if (numOfElev > 0 && numOfElev <=3){
            enteredCorrectly = true;
        }
        else{
            cout << "Enter # of Elevators (1-3)" << endl;
            cin >> numOfElev;
        }
    }

    Building bldg(numOfFloors, numOfElev);

    //Ask for building entrances where passengers enter
    vector<bool> entrance;
    char response = 'E'; // empty
    int floorNo = 0;
    cout << "Enter floors where paseengers enter. Answer Y/N when prompted with floor #" << endl;
    for (floorNo = 0; floorNo < numOfFloors; floorNo++){
        while (response != 'Y' && response != 'y' && response != 'N' && response != 'n'){
            cout << "Enter from floor " << floorNo << "? (Y/N): " << endl;
            cin >> response;
        }
        if (response == 'Y') {
            entrance.push_back(true);
        }
        else{
            entrance.push_back(false);
        }

        response = 'E';
    }

    // create clock
    int clock = 0;

    //initialize variables we will need to generate an entering passenger
    int numOfPassengersGenerated = 0; // generate 0-1 passenegers every 30 seconds
    int passengerID = 0; // starts ID from 1
    //int direction = 0; // direction passenger is moving - up/down
    int destFloor = -1; // where is the passenger going - floorNo 0-numOfFloors
    bool notGenerated = true; // destination floor for passenger


    cout << "Starting simulation" << endl;
    cout << "Clock set to 0" << endl;
    cout << "Simulting building elevators for 12 hours from 7 AM - 7 PM (43,200 seconds)" << endl;
    for (clock = 0; clock < 43200; clock++){
        //randomly generate passengers entering building
        //add 0-1 pasengers at each entrance every 60 seconds; approximately 30 passengers every entrance per hour
        //2 entrances will lead to ~720 passengers
        for (floorNo = 0; floorNo < numOfFloors; floorNo++){

            if (entrance[floorNo] && clock % 60 == 0) {
                numOfPassengersGenerated = (rand() % 2);
            //	cout << "numOfPassengers = " << numOfPassengersGenerated << endl;

                for (int i = 0; i < numOfPassengersGenerated; i++){
                    passengerID++;
                    while (notGenerated){
                        destFloor = (rand()%numOfFloors);
                        if (destFloor != floorNo){
                            notGenerated = false;
                        }
                    }
                    notGenerated = true;
                    // add passenger to hallway queue of building entrance floor
                    bldg.addHallwayPassenger(passengerID, clock, floorNo, destFloor);
                    cout << "Passenger " << passengerID << " added at time " << clock << " to floor " << floorNo << " destination " << destFloor << endl;
                }

            }
        }

        //should elevators transition to a new state


        bldg.transitionState(clock);

    }
    //print statistics for the building
    bldg.printStats();

}

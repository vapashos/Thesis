//============================================================================
// Name        : NetworkSimulator.cpp
// Author      : vasileios pashos
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Simulator.h"
#include <cstdlib>
#include <fstream>
#include <bitset>

int main() {
	cout << "Hello World!!!" << endl; // prints Hello World!!!

	string u=getenv("USER");

//	string filename="/home/vapashos/JSVM/jsvm/JSVM/H264Extension/data/test.264";
//	string traceFile="/home/vapashos/JSVM/jsvm/JSVM/H264Extension/data/trace.txt";
	string filename="/home/"+u+"/JSVM/jsvm/JSVM/H264Extension/data/test.264";
	string traceFile="/home/"+u+"/JSVM/jsvm/JSVM/H264Extension/data/trace.txt";




	Simulator sim=Simulator(5,filename,traceFile);
	sim.createMeshTopology();
	sim.s->createCodedPacket(sim.s->segments[12]);

	char c;
	for(int simTime=0;simTime<2000;simTime++){
		cout<<"###############################################################"<<endl;
		cout<<"#                                    TIMESLOT "<<simTime+1<<"                           							#"<<endl;
		cout<<"###############################################################"<<endl;
		sim.simulate3GTransmissions(simTime);
		sim.simulateWIFIBroadcasts(simTime);
		//cin>>c;
		//sim.showChannelBuffer();
		if(channel3G::status==0 ){
			cout<<"All downloads on 3G finished "<<endl;
			if(sim.checkNodeQueues(simTime)){
				cout<<"There is nothing to be transmitted inside the lan"<<endl;
				break;
			}

			//sim.showNodeSegmentList();
			//break;
		}
		/*if(simTime%100==0)
			cin>>c;*/


		cout<<"********************Enf OF   TimeSlot "<<simTime+1<<" ***********************"<<endl;
	//	if(simTime%2==0)
			//cin>>c;

	}
	cout.flush();
	cout<<"*****************************************"<<endl;


	cout<<"finished"<<endl;
	cout<<"-------------------------- "<<endl;

	return 0;
}

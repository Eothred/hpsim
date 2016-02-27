#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include "beamline.h"
#include "simulation_engine.h"
#include "beam.h"
#include "init.h"

int main()
{
  BeamLine bl;
  DBConnection dbcon_ptr("../../db/offline-ccl.db");
  GenerateBeamLine(bl, &dbcon_ptr);
//  bl.Print("05BA101", "05RG103");

  Beam beam;
  beam.InitBeamFromFile("Hm_clz_64k.txt");

  Scheff scheff(32, 128/2, 3);
  scheff.SetAdjBunchCutoffW(0.8);
  scheff.SetInterval(0.1);
  scheff.SetMeshSizeCutoffW(40.0);

  SimulationEngine se;
  se.InitEngine(&beam, &bl, &scheff);
  se.Simulate();//"CLZ", "06DT");//"05RG101");
  beam.PrintToFile("end.txt", "");
  //se.Simulate("01QM00U", "02DR02");
  
//  se.Start();
//  std::cout << bl.GetSize() << std::endl;
//  std::cout << bl.GetElementModelIndex("04qm01") << std::endl;
//  std::cout << bl.GetElementName(bl.GetElementModelIndex("04qm01")) << std::endl;
//  std::cout << bl.GetNumOfMonitors() << std::endl;
//  std::vector<uint> indices = bl.GetMonitoredElementsIndices();
//  std::copy(indices.begin(), indices.end(), std::ostream_iterator<uint>(std::cout, ", "));

}
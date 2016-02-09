#ifndef SIMULATION_ENGINE_CU_H
#define SIMULATION_ENGINE_CU_H

extern "C"
{
  void SetConstOnDevice(SimulationConstOnDevice*);
  void Init(Beam*, BeamLine*, SpaceCharge*, SimulationParam&);
  void Cleanup();
  void StepSimulationKernelCall(Beam*, BeamLine*, SpaceCharge*, SimulationParam&, uint);
  void SimulateDrift(Drift*);
  void SimulateQuad(Quad*);
  void SimulateRFGap(RFGap*);
  void SimulateRotation(Rotation*);
} // extern "C"

#endif
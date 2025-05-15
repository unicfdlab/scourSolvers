// Diffusivity
// dimensionedScalar K_0("K_0", dimensionSet(0, 2, -1, 0, 0, 0, 0), 0.0005);
bool sandSlide(sedimentProperties.lookupOrDefault<bool>("sandSlide", true));
bool adaptiveAngle(sedimentProperties.lookupOrDefault<bool>("adaptiveAngle", false));
Info<<"adaptiveAngle: "<<adaptiveAngle<<"\n"<<endl;

dimensionedScalar K_0("K_0", dimensionSet(0, 2, -1, 0, 0, 0, 0), sedimentProperties);

scalar sandTimeStep(sedimentProperties.lookupOrDefault<scalar>("sandTimeStep", 0.001));
scalar sandIter(sedimentProperties.lookupOrDefault<scalar>("sandIter", 100));
scalar coeffSandT = sandTimeStep/runTime.deltaTValue();

dimensionedScalar sandTime("sandTime", dimensionSet(0, 0, 1, 0, 0, 0, 0), 1);
sandTime.value() = sandTimeStep;
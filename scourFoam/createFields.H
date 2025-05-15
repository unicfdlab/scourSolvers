#include "createRDeltaT.H"

Info<< "Reading field p\n" << endl;
volScalarField p
(
    IOobject
    (
        "p",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Reading field U\n" << endl;
volVectorField U
(
    IOobject
    (
        "U",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "\nReading g" << endl;
const meshObjects::gravity& g = meshObjects::gravity::New(runTime);

Info<<"Initialize wallShearStress"<<endl;
volVectorField wallShearStress
(
    IOobject
    (
        "wallShearStress",
        runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    mesh,
    // dimensionedVector(sqr(dimLength)/sqr(dimTime), Zero)
    dimensionedVector(dimPressure, Zero)
);

Info<<"Initialize cellDisplacement"<<endl;
volVectorField cellDisplacementCustom
(
    IOobject
    (
        "cellDisplacementCustom",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh,
    // dimensionedVector(sqr(dimLength)/sqr(dimTime), Zero)
    dimensionedVector(dimLength, Zero)
);

// dimensionedScalar G_0()

#include "createPhi.H"


label pRefCell = 0;
scalar pRefValue = 0.0;
setRefCell(p, pimple.dict(), pRefCell, pRefValue);
mesh.setFluxRequired(p.name());


singlePhaseTransportModel laminarTransport(U, phi);

autoPtr<incompressible::turbulenceModel> turbulence
(
    incompressible::turbulenceModel::New(U, phi, laminarTransport)
);

#include "createMRF.H"
#include "createFvOptions.H"



// Create faFields

// Volume-to surface mapping object
const volSurfaceMapping vsm(aMesh);

// Initialize faFields

Info<< "Initiali field pS" << endl; // added
areaScalarField pSurf
(
    IOobject
    (
        "pSurf",
        runTime.timeName(),
        aMesh.thisDb(),
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    aMesh,
    dimensionedScalar(dimPressure, Zero)
);

areaVectorField wallShearStressSurf
(
    IOobject
    (
        "wallShearStressSurf",
        runTime.timeName(),
        aMesh.thisDb(),
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    aMesh,
    dimensionedVector(dimPressure, Zero)
);

areaScalarField zetaInit
(
    IOobject
    (
        "zetaInit",
        runTime.timeName(),
        aMesh.thisDb(),
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    aMesh.areaCentres().component(2),
    "zeroGradient"
);

areaScalarField zeta
(
    IOobject
    (
        "zeta",
        runTime.timeName(),
        aMesh.thisDb(),
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
   zetaInit
//    aMesh,
//    dimensionedScalar(dimLength, Zero),
//    "zeroGradient"
);



areaScalarField zeta0 //Orig
(
    IOobject
    (
        "zeta0",
        runTime.timeName(),
        aMesh.thisDb(),
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    aMesh,
    dimensionedScalar(dimLength, Zero)
);

//zeta = zetaInit;

areaScalarField deltaZeta
(
    IOobject
    (
        "deltaZeta",
        runTime.timeName(),
        aMesh.thisDb(),
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    aMesh,
    dimensionedScalar(dimLength, Zero)
);

areaScalarField zetaSumm
(
    IOobject
    (
        "zetaSumm",
        runTime.timeName(),
        aMesh.thisDb(),
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    aMesh,
    dimensionedScalar(dimLength, Zero)
);

areaVectorField Gamma
(
    IOobject
    (
        "Gamma",
        runTime.timeName(),
        aMesh.thisDb(),
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    aMesh,
    dimensionedVector(dimless, Zero)
);

areaScalarField T_c
(
    IOobject
    (
        "T_c",
        runTime.timeName(),
        aMesh.thisDb(),
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    aMesh,
    dimensionedScalar(dimensionSet(1, -1, -2, 0, 0, 0, 0), Zero)
);

areaVectorField G
(
    IOobject
    (
        "G",
        runTime.timeName(),
        aMesh.thisDb(),
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    aMesh,
    dimensionedVector(dimensionSet(0, 2, -1, 0, 0, 0, 0), Zero),
    "zeroGradient"
);

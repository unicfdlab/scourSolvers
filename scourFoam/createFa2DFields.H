areaScalarField cosGamma
(
    IOobject
    (
        "cosGamma",
        runTime.timeName(),
        aMesh.thisDb(),
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    aMesh,
    dimensionedScalar(dimless, Zero)
);

areaScalarField moduleWSS
(
    IOobject
    (
        "moduleWSS",
        runTime.timeName(),
        aMesh.thisDb(),
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    aMesh,
    dimensionedScalar(dimensionSet(1, -1, -2, 0, 0, 0, 0), Zero)
);

areaScalarField diffWSS
(
    IOobject
    (
        "moduleWSS",
        runTime.timeName(),
        aMesh.thisDb(),
        IOobject::READ_IF_PRESENT,
        IOobject::AUTO_WRITE
    ),
    aMesh,
    dimensionedScalar(dimensionSet(0.5, -0.5, -1, 0, 0, 0, 0), Zero)
);

areaVectorField gradZeta
(
    IOobject
    (
        "gradZeta",
        runTime.timeName(),
        aMesh.thisDb(),
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    aMesh,
    dimensionedVector(dimless, Zero),
    "zeroGradient"
);

areaScalarField divZeta
(
    IOobject
    (
        "divZeta",
        runTime.timeName(),
        aMesh.thisDb(),
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    aMesh,
    dimensionedScalar(dimless, Zero),
    "zeroGradient"
);

areaScalarField divG
(
    IOobject
    (
        "divG",
        runTime.timeName(),
        aMesh.thisDb(),
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    aMesh,
    dimensionedScalar(dimLength/dimTime, Zero)
);

areaScalarField cosAlpha
(
    IOobject
    (
        "cosAlpha",
        runTime.timeName(),
        aMesh.thisDb(),
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    aMesh,
    dimensionedScalar(dimless, Zero)
);

areaScalarField sinAlpha
(
    IOobject
    (
        "sinAlpha",
        runTime.timeName(),
        aMesh.thisDb(),
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    aMesh,
    dimensionedScalar(dimless, Zero)
);

areaScalarField zeroWSS
(
    IOobject
    (
        "zeroWSS",
        runTime.timeName(),
        aMesh.thisDb(),
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    aMesh,
    dimensionedScalar(dimensionSet(0.5, -0.5, -1, 0, 0, 0, 0), Zero)
);

areaScalarField K
(
    IOobject
    (
        "K",
        runTime.timeName(),
        aMesh.thisDb(),
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    aMesh,
    dimensionedScalar(dimensionSet(0, 2, -1, 0, 0, 0, 0), Zero)
);

areaScalarField laplacianZeta
(
    IOobject
    (
        "laplacianZeta",
        runTime.timeName(),
        aMesh.thisDb(),
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    aMesh,
    dimensionedScalar(dimensionSet(0, 1, -1, 0, 0, 0, 0), Zero)
);

areaScalarField phiAngle
(
    IOobject
    (
        "phiAngle",
        runTime.timeName(),
        aMesh.thisDb(),
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    aMesh,
    dimensionedScalar(dimless, Zero)
);

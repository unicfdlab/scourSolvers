IOdictionary sedimentProperties
(
    IOobject
    (
        "sedimentProperties",
        runTime.constant(),
        mesh,
        IOobject::MUST_READ,
        IOobject::NO_WRITE
    )
);

dimensionedScalar epsilon("epsilon", dimless, sedimentProperties);

dimensionedScalar rho_s("rho_s", dimDensity, sedimentProperties);
dimensionedScalar rho_w("rho_w", dimDensity, sedimentProperties);

dimensionedScalar kappa("kappa", dimless, sedimentProperties);

dimensionedScalar respAngle("respAngle", dimless, sedimentProperties);

dimensionedScalar c_x("c_x", dimless, sedimentProperties);

dimensionedScalar d_50("d_50", dimLength, sedimentProperties);

dimensionedScalar G_0("G_0", dimensionSet(-1.5, 4.5, 0, 0, 0, 0, 0), Zero);

dimensionedScalar Theta_0("Theta_0", dimless, Zero);

dimensionedScalar T_0("T_0", dimensionSet(1, -1, -2, 0, 0, 0, 0), Zero);

dimensionedScalar g_z("g_z", dimensionSet(0, 1, -2, 0, 0, 0, 0), 9.8);

dimensionedVector Ones("Ones", dimless, vector (1, 1, 1));

Theta_0 = 9*pow(kappa, 2)*tan(respAngle)/c_x/8;
Info<<"Theta: "<<Theta_0.value()<<endl;

G_0 = 4/(3*kappa*tan(respAngle)*(rho_s - rho_w)*sqrt(rho_w));
Info<< "G_0: "<<G_0.value()<<endl;

T_0 = 9*pow(kappa, 2)*(rho_s - rho_w)*tan(respAngle)*d_50*g_z/c_x/8;
Info<<"T_0: "<<T_0.value()<<endl;

// Read control properties
scalar sedTimeStep(sedimentProperties.lookupOrDefault<scalar>("sedTimeStep", 0.001));
scalar sedIter(sedimentProperties.lookupOrDefault<scalar>("sedIter", 10));
scalar coeffT = sedTimeStep/runTime.deltaTValue();

Info << "sedTimeStep: " << sedTimeStep << endl;
Info << "sedIter: " << sedIter << endl;

bool onlySandSlide(sedimentProperties.lookupOrDefault<bool>("onlySandSlide", false));

dimensionedScalar sedTime("sedTime", dimensionSet(0, 0, 1, 0, 0, 0, 0), 1);
sedTime.value() = sedTimeStep;

word patchName(sedimentProperties.lookup("patchName"));

#include "sandSlideProperties.H"

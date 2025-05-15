// shearStress.dimensions().reset(Reff.dimensions());

volSymmTensorField Reff(turbulence->devReff());

//U.write();
//Reff.write();

wallShearStress.dimensions().reset(Reff.dimensions());

vectorField& ssp = wallShearStress.boundaryFieldRef()[patchID];
const vectorField& Sfp = mesh.Sf().boundaryField()[patchID];
const scalarField& magSfp = mesh.magSf().boundaryField()[patchID];
const symmTensorField& Reffp = Reff.boundaryField()[patchID];
 
ssp = (-Sfp/magSfp) & Reffp;
               
pSurf.primitiveFieldRef() = p.boundaryField()[patchID]*rho_w.value();
wallShearStressSurf.primitiveFieldRef() = -ssp*rho_w.value();



Info << "\n2D model\n" << endl;

moduleWSS.primitiveFieldRef() = Foam::mag(wallShearStressSurf.primitiveFieldRef());

cosAlpha.primitiveFieldRef() = wallShearStressSurf.primitiveFieldRef().component(0)/moduleWSS.primitiveFieldRef();
sinAlpha.primitiveFieldRef() = wallShearStressSurf.primitiveFieldRef().component(1)/moduleWSS.primitiveFieldRef();

moduleWSS.correctBoundaryConditions();
cosAlpha.correctBoundaryConditions();
sinAlpha.correctBoundaryConditions();

for(int i = 0; i < sedIter; i++)
{
    Info<<"Sediment iteration: "<< i << endl;

    zeta0 = zeta;
    zeta0.correctBoundaryConditions();    
    
    gradZeta = fac::grad(zeta);
    gradZeta.correctBoundaryConditions();
    
    cosGamma = Foam::sqrt(1/(1 + Foam::magSqr(gradZeta)));
    cosGamma.correctBoundaryConditions();

    Gamma = gradZeta/tan(respAngle)/cosGamma;
    Gamma.correctBoundaryConditions();
    
    areaScalarField F = (1 - sqr(Gamma.component(0)) - sqr(Gamma.component(1)));
    
    T_c = T_0*cosGamma*Foam::max(0.0,F/(Foam::max(0.1, sqrt(Foam::max(0.0,1 - sqr(Gamma.component(1)))) - Gamma.component(0))));
    T_c.correctBoundaryConditions();
    
    diffWSS.primitiveFieldRef() = Foam::sqrt(moduleWSS.primitiveFieldRef()) - Foam::sqrt(T_c.primitiveFieldRef());
    diffWSS.correctBoundaryConditions();
    
    G.primitiveFieldRef().replace(0, G_0*moduleWSS/g_z   // /max(0.05,1-sqr(Gamma.component(0)))
                    * 
                    Foam::max(zeroWSS.primitiveFieldRef(), diffWSS.primitiveFieldRef())//Foam::sqrt(max(zeroWSS*zeroWSS, T_c)))
                    *(
                        cosAlpha
                        *(
                            1 - 1/tan(respAngle)
                            *(
                                cosAlpha*gradZeta.component(0)
                                +
                                sinAlpha*gradZeta.component(1)
                            )
                        )
                        - 4/5*sinAlpha/tan(respAngle)
                        *(
                            sinAlpha*gradZeta.component(0)
                            -
                            cosAlpha*gradZeta.component(1)
                        )
                    ));

    G.primitiveFieldRef().replace(1, G_0*moduleWSS/g_z // /max(0.05, 1-sqr(Gamma.component(1)))
                    * 
                    Foam::max(zeroWSS.primitiveFieldRef(), diffWSS.primitiveFieldRef())//Foam::sqrt(max(zeroWSS*zeroWSS, T_c)))
                    *
                    (
                        sinAlpha
                        *(
                            1 -
                            (
                                cosAlpha*gradZeta.component(0)
                                +
                                sinAlpha*gradZeta.component(1)
                            )/tan(respAngle)
                        )
                        + 4/5*cosAlpha/tan(respAngle)
                        *(
                            sinAlpha*gradZeta.component(0)
                            -
                            cosAlpha*gradZeta.component(1)
                        )
                    ));
    G.correctBoundaryConditions();

    divG = fac::div(G);
    divG.correctBoundaryConditions();

    zeta = zeta0 - sedTime/(1-epsilon)*fac::div(G);
    deltaZeta = - sedTime/(1-epsilon)*fac::div(G);
    zeta.correctBoundaryConditions();
    Info << min(deltaZeta) << "  " << max(deltaZeta) << endl;
}

    zetaSumm = zeta - zetaInit;
    zetaSumm.correctBoundaryConditions();

    Info << min(zeta) << "  " << max(zeta) << endl;
    Info << min(zetaSumm) << "  " << max(zetaSumm) << endl;

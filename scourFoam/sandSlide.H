Info << "\nSandslide algorithm\n" << endl;
// Info<<"Zeta:\n"<<
zeta0 = zeta;
zeta0.correctBoundaryConditions(); 

for(int i = 0; i < sandIter; i++)
{
    Info<<"Sandslide iteration: "<< i << endl;

    gradZeta = fac::grad(zeta);
    // Info<<"gradZeta:\n"<<gradZeta<<endl;
    gradZeta.correctBoundaryConditions();

    if(adaptiveAngle)
    {
        // Info<<"Adaptive angle is used!"<<endl;
        divZeta.primitiveFieldRef() = mag(gradZeta.primitiveFieldRef())/tan(phiAngle.primitiveFieldRef());
    }
    else
    {
        // Info<<"Non-adaptive angle is used!"<<endl;
        divZeta = mag(gradZeta)/tan(respAngle); // Note that it is not a divergence. It was done intentionally
    }
    
    divZeta.correctBoundaryConditions();

    K = K_0;//*pos(divZeta - 1);// + SMALL);
    K.correctBoundaryConditions();

    laplacianZeta = fac::laplacian(K, zeta);
    laplacianZeta.correctBoundaryConditions();

    zeta += sandTime*laplacianZeta;
    zeta.correctBoundaryConditions();

}

    zetaSumm = zeta - zetaInit;
    zetaSumm.correctBoundaryConditions();
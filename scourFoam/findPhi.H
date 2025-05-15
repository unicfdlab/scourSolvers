// Here we are calculating new values of the angle of repose

phiAngle.primitiveFieldRef() = respAngle.value()
                            +
                            0.1*
                            max(zeroWSS, moduleWSS.primitiveFieldRef() - T_c.primitiveFieldRef());

forAll(phiAngle, i)
{
    if(phiAngle[i] < respAngle.value() + 0.1)
        phiAngle[i] = respAngle.value() + 0.1;
}

phiAngle.correctBoundaryConditions();

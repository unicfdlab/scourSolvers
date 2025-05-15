// Find the reference to the location of pointDisplacement field
pointVectorField& pointDisplacement = const_cast<pointVectorField&>
(
	mesh.objectRegistry::lookupObject<pointVectorField>
	(
	"pointDisplacement"
	)
);

volVectorField& cellDisplacement = const_cast<volVectorField&>
(
	mesh.objectRegistry::lookupObject<volVectorField>
	(
	"cellDisplacement"
	)
);

Info<<"\ncellDisplacement\n"<<endl;
cellDisplacement.boundaryFieldRef()[patchID].replace(2, zetaSumm);
cellDisplacement.correctBoundaryConditions();

volPointInterpolation vpi(mesh);

pointDisplacement = vpi.interpolate(cellDisplacement);
pointDisplacement.correctBoundaryConditions();
// mesh.controlledUpdate();
mesh.update();

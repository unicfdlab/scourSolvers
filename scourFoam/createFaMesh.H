// Create faMesh

// Find the required pathc
label patchID=mesh.boundaryMesh().findPatchID(patchName);

// create faMesh
faMesh aMesh(mesh.boundaryMesh()[patchID]);

// write faMesh
aMesh.write();
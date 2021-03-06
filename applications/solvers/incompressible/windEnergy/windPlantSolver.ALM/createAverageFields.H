    // Create and read in initial time-averaged velocity field.
    Info << "Creating time-average velocity field, UAvg..." << endl;
    volVectorField UAvg
    (
        IOobject
        (
            "UAvg",
            runTime.timeName(),
            mesh,
            IOobject::READ_IF_PRESENT,
            IOobject::AUTO_WRITE
        ),
        mesh,
        dimensionedVector("UAvg",dimensionSet(0, 1, -1, 0, 0, 0, 0),vector::zero)
    );


    Info << "Creating time-average vorticity field, omegaAvg..." << endl;
    volVectorField omegaAvg
    (
        IOobject
        (
            "omegaAvg",
            runTime.timeName(),
            mesh,
            IOobject::READ_IF_PRESENT,
            IOobject::AUTO_WRITE
        ),
        mesh,
        dimensionedVector("omegaAvg",dimensionSet(0, 0, -1, 0, 0, 0, 0),vector::zero)
    );


    // Create and read in initial time-averaged temperature field.
    Info << "Creating time-averaged temperature field, TAvg..." << endl;
    volScalarField TAvg
    (
        IOobject
        (
            "TAvg",
            runTime.timeName(),
            mesh,
            IOobject::READ_IF_PRESENT,
            IOobject::AUTO_WRITE
        ),
        mesh,
        dimensionedScalar("TAvg",dimensionSet(0, 0, 0, 1, 0, 0, 0),0.0)
    );

    Info << "Creating time-averaged pressure field, p_rghAvg..." << endl;
    volScalarField p_rghAvg
    (
        IOobject
        (
            "p_rghAvg",
            runTime.timeName(),
            mesh,
            IOobject::READ_IF_PRESENT,
            IOobject::AUTO_WRITE
        ),
        mesh,
        dimensionedScalar("p_rghAvg",dimensionSet(0, 2, -2, 0, 0, 0, 0),0.0)
    );

    // Create and read in initial RMS velocity field.
    Info << "Creating RMS velocity field, uRMS..." << endl;
    volVectorField uRMS
    (
        IOobject
        (
            "uRMS",
            runTime.timeName(),
            mesh,
            IOobject::READ_IF_PRESENT,
            IOobject::AUTO_WRITE
        ),
        mesh,
        dimensionedVector("uRMS",dimensionSet(0, 1, -1, 0, 0, 0, 0),vector::zero)
    );

    // Create and read in initial RMS temperature field.
    Info << "Creating RMS temperature field, TRMS..." << endl;
    volScalarField TRMS
    (
        IOobject
        (
            "TRMS",
            runTime.timeName(),
            mesh,
            IOobject::READ_IF_PRESENT,
            IOobject::AUTO_WRITE
        ),
        mesh,
        dimensionedScalar("TRMS",dimensionSet(0, 0, 0, 1, 0, 0, 0),0.0)
    );

    // Create the time-averaged Reynolds stress tensor field.
    Info<< "Creating the time-averaged Reynolds stress field, uuPrime2..." << endl;
    volSymmTensorField uuPrime2
    (
        IOobject
        (
            "uuPrime2",
            runTime.timeName(),
            mesh,
            IOobject::READ_IF_PRESENT,
            IOobject::AUTO_WRITE
        ),
        mesh,
        dimensionedSymmTensor("uuPrime2",dimensionSet(0, 2, -2, 0, 0, 0, 0),symmTensor::zero)
    );

    // Create the time-averaged temperature-temperature correlation field.
    Info<< "Creating the time-averaged temperature-temperature correlation field, TTPrime2..." << endl;
    volScalarField TTPrime2
    (
        IOobject
        (
            "TTPrime2",
            runTime.timeName(),
            mesh,
            IOobject::READ_IF_PRESENT,
            IOobject::AUTO_WRITE
        ),
        mesh,
        dimensionedScalar("TTPrime2",dimensionSet(0, 0, 0, 2, 0, 0, 0),0.0)
    );

    // Create the time-averaged velocity-temperature correlation field.
    Info<< "Creating the time-averaged velocity-temperature correlation field, uTPrime2..." << endl;
    volVectorField uTPrime2
    (
        IOobject
        (
            "uTPrime2",
            runTime.timeName(),
            mesh,
            IOobject::READ_IF_PRESENT,
            IOobject::AUTO_WRITE
        ),
        mesh,
        dimensionedVector("uTPrime2",dimensionSet(0, 1, -1, 1, 0, 0, 0),vector::zero)
    );

    // Create mean SGS stress field
    Info<< "Creating mean SGS stress field, Rmean..." << endl;
    volSymmTensorField Rmean
    (
        IOobject
        (
            "Rmean",
            runTime.timeName(),
            mesh,
            IOobject::READ_IF_PRESENT,
            IOobject::AUTO_WRITE
        ),
        mesh,
        dimensionedSymmTensor("Rmean",dimensionSet(0, 2, -2, 0, 0, 0, 0),symmTensor::zero)
    );

    // Create mean SGS temperature flux field
    Info<< "Creating mean SGS temperature flux field, qmean..." << endl;
    volVectorField qmean
    (
        IOobject
        (
            "qmean",
            runTime.timeName(),
            mesh,
            IOobject::READ_IF_PRESENT,
            IOobject::AUTO_WRITE
        ),
        mesh,
        dimensionedVector("qmean",dimensionSet(0, 1, -1, 1, 0, 0, 0),vector::zero)
    );

    // Create mean SGS viscosityfield
    Info<< "Creating mean SGS viscosity field, nuSGSmean..." << endl;
    volScalarField nuSGSmean
    (
        IOobject
        (
            "nuSGSmean",
            runTime.timeName(),
            mesh,
            IOobject::READ_IF_PRESENT,
            IOobject::AUTO_WRITE
        ),
        mesh,
        dimensionedScalar("nuSGSMean",dimensionSet(0, 2, -1, 0, 0, 0, 0),0.0)
    );

    Info<< "Creating SGS energy field, kSGS..." << endl;
    volScalarField kSGS
    (
        IOobject
        (
            "kSGS",
            runTime.timeName(),
            mesh,
            IOobject::READ_IF_PRESENT,
            IOobject::AUTO_WRITE
        ),
        mesh,
        dimensionedScalar("kSGS",dimensionSet(0, 2, -2, 0, 0, 0, 0),0.0)
    );

  //  Info<< "Creating SGS viscosity field, nuSGS..." << endl;
  //  volScalarField nuSGS
  //  (
  //      IOobject
  //      (
  //          "nuSGS",
  //          runTime.timeName(),
  //          mesh,
  //          IOobject::READ_IF_PRESENT,
  //          IOobject::AUTO_WRITE
  //      ),
  //      mesh,
  //      dimensionedScalar("nuSGS",dimensionSet(0, 2, -1, 0, 0, 0, 0),0.0)
  //  );


    // Create the resolved-scale tke field.
    Info<< "Creating the resolved scale turbulent kinetic energy field, kResolved..." << endl;
    volScalarField kResolved
    (
        IOobject
        (
            "kResolved",
            runTime.timeName(),
            mesh,
            IOobject::READ_IF_PRESENT,
            IOobject::AUTO_WRITE
        ),
        mesh,
        dimensionedScalar("kResolved",dimensionSet(0, 2, -2, 0, 0, 0, 0),0.0)
    );

    // Create the mean SGS tke field
    Info<< "Creating the mean SGS turbulent kinetic energy field, kSGSMean..." << endl;
    volScalarField kSGSmean
    (
        IOobject
        (
            "kSGSmean",
            runTime.timeName(),
            mesh,
            IOobject::READ_IF_PRESENT,
            IOobject::AUTO_WRITE
        ),
        turbulence->k()
    );
 
    Info<< "Creating the mean SGS turbulent kinetic energy dissipation field, kSGSMean..." << endl;
    volScalarField epsilonSGSmean
    (
        IOobject
        (
            "epsilonSGSmean",
            runTime.timeName(),
            mesh,
            IOobject::READ_IF_PRESENT,
            IOobject::AUTO_WRITE
        ),
        mesh,
        dimensionedScalar("epsilonSGSmean",dimensionSet(0, 2, -3, 0, 0, 0, 0),0.0)
    );


    // Declare total averaging times for average fields and correlation fields.
    scalar avgTimeSum = max(runTime.value() - avgStartTime, 0.0);
    scalar corrTimeSum = max(runTime.value() - corrStartTime, 0.0);
    Info << "avgTimeSum = " << avgTimeSum << tab << "corrTimeSum = " << corrTimeSum << endl;

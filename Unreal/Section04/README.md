<div id="table-of-contents">
<h2>Table of Contents</h2>
<div id="text-table-of-contents">
<ul>
<li><a href="#orgdebd7c6">1. L139 Creat default sub objects in C++</a>
<ul>
<li><a href="#orgdab1df7">1.1. goal</a></li>
<li><a href="#org2162189">1.2. result</a></li>
<li><a href="#orge7b7feb">1.3. notes in lecture</a></li>
<li><a href="#org509c028">1.4. question that I do not understand</a>
<ul>
<li><a href="#orgbcfaaf2">1.4.1. crash</a></li>
</ul>
</li>
<li><a href="#orgf0531f1">1.5. a-ha moment</a>
<ul>
<li><a href="#orgb8a609c">1.5.1. pointer to pointer</a></li>
</ul>
</li>
</ul>
</li>
</ul>
</div>
</div>

<a id="orgdebd7c6"></a>

# L139 Creat default sub objects in C++


<a id="orgdab1df7"></a>

## goal

Refactoring the code so that the aiming log is a separated class.


<a id="org2162189"></a>

## result

![img](Source/screenCapture/tankBodyOutPutCorrectAimingLocation.png)


<a id="orge7b7feb"></a>

## notes in lecture


<a id="org509c028"></a>

## question that I do not understand


<a id="orgbcfaaf2"></a>

### crash

When I try to get the owner of the 'aiming component', the UE
crush without any info.


<a id="orgf0531f1"></a>

## a-ha moment


<a id="orgb8a609c"></a>

### pointer to pointer

This is the first time that I use it intentionlly in real
programming, and it is in this lesson, that I've learnt that it is
useful when you want to separate a function in a class.

I've stuck in this issue for a long time. At first, I think I
should write another getter to return a 'UTankAimingComponent' so
that the tank can use AimAt method defined in
'UTankAimingComponent' class.

UTankAimingComponent* ATankAIController::GetAimingComponent() const
{
    return Cast<UTankAimingComponent>(GetPawn());
}


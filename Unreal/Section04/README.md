<div id="table-of-contents">
<h2>Table of Contents</h2>
<div id="text-table-of-contents">
<ul>
<li><a href="#org8e07690">1. L139 Creat default sub objects in C++</a>
<ul>
<li><a href="#org8f24d46">1.1. goal</a></li>
<li><a href="#org83d1946">1.2. result</a></li>
<li><a href="#org3097914">1.3. notes in lecture</a></li>
<li><a href="#orgfb6f80a">1.4. question that I do not understand</a>
<ul>
<li><a href="#org65412d1">1.4.1. crash</a></li>
</ul>
</li>
<li><a href="#org496c3e6">1.5. a-ha moment</a>
<ul>
<li><a href="#orged3db71">1.5.1. pointer to pointer</a></li>
</ul>
</li>
</ul>
</li>
</ul>
</div>
</div>

<a id="org8e07690"></a>

# L139 Creat default sub objects in C++


<a id="org8f24d46"></a>

## goal

Refactoring the code so that the aiming log is a separated class.


<a id="org83d1946"></a>

## result

![img](Source/screenCapture/tankBodyOutPutCorrectAimingLocation.png)


<a id="org3097914"></a>

## notes in lecture


<a id="orgfb6f80a"></a>

## question that I do not understand


<a id="org65412d1"></a>

### crash

When I try to get the owner of the 'aiming component', the UE
crush without any info.


<a id="org496c3e6"></a>

## a-ha moment


<a id="orged3db71"></a>

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


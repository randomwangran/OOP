<div id="table-of-contents">
<h2>Table of Contents</h2>
<div id="text-table-of-contents">
<ul>
<li><a href="#orgda0752e">1. L139 Creat default sub objects in C++</a>
<ul>
<li><a href="#org9155146">1.1. goal</a></li>
<li><a href="#orgc5f9c45">1.2. result</a></li>
<li><a href="#org566104b">1.3. notes in lecture</a></li>
<li><a href="#org8fe9d20">1.4. question that I do not understand</a>
<ul>
<li><a href="#orga0eaeef">1.4.1. crash</a></li>
</ul>
</li>
<li><a href="#orgf438b5c">1.5. a-ha moment</a>
<ul>
<li><a href="#orgb43c77c">1.5.1. pointer to pointer</a></li>
</ul>
</li>
</ul>
</li>
</ul>
</div>
</div>

<a id="orgda0752e"></a>

# L139 Creat default sub objects in C++


<a id="org9155146"></a>

## goal

Refactoring the code so that the aiming log is a separated class.


<a id="orgc5f9c45"></a>

## result

![img](Source/screenCapture/tankBodyOutPutCorrectAimingLocation.png)


<a id="org566104b"></a>

## notes in lecture


<a id="org8fe9d20"></a>

## question that I do not understand


<a id="orga0eaeef"></a>

### crash

When I try to get the owner of the 'aiming component', the UE
crush without any info.


<a id="orgf438b5c"></a>

## a-ha moment


<a id="orgb43c77c"></a>

### pointer to pointer

This is the first time that I use it intentionlly in real
programming, and it is in this lesson, that I've learnt that it is
useful when you want to separate a function in a class.

I've stuck in this issue for a long time. At first, I think I
should write another getter to return a 'UTankAimingComponent' so
that the tank can use AimAt method defined in
'UTankAimingComponent' class.

```cpp
UTankAimingComponent\* ATankAIController::GetAimingComponent() const
{
    return Cast<UTankAimingComponent>(GetPawn());
}
```


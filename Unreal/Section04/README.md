<div id="table-of-contents">
<h2>Table of Contents</h2>
<div id="text-table-of-contents">
<ul>
<li><a href="#orgddbb134">1. L139 Creat default sub objects in C++</a>
<ul>
<li><a href="#orgab47645">1.1. goal</a></li>
<li><a href="#orgbbad9b7">1.2. result</a></li>
<li><a href="#orge76dc4d">1.3. notes</a></li>
<li><a href="#org91ce224">1.4. question that I do not understand</a>
<ul>
<li><a href="#orgc3aded0">1.4.1. UE4 .19 crash when try to access directly from 'GetAimingComponent' class</a></li>
</ul>
</li>
<li><a href="#orgfbd0daa">1.5. a-ha moment</a>
<ul>
<li><a href="#org2226b6d">1.5.1. pointer to pointer</a></li>
</ul>
</li>
</ul>
</li>
</ul>
</div>
</div>

<a id="orgddbb134"></a>

# L139 Creat default sub objects in C++


<a id="orgab47645"></a>

## goal

Refactoring the code so that the aiming log is a separated class.


<a id="orgbbad9b7"></a>

## result

![img](Source/screenCapture/tankBodyOutPutCorrectAimingLocation.png)


<a id="orge76dc4d"></a>

## notes


<a id="org91ce224"></a>

## question that I do not understand


<a id="orgc3aded0"></a>

### UE4 .19 crash when try to access directly from 'GetAimingComponent' class

1.  asked question

    [My question url](https://www.udemy.com/unrealcourse/learn/v4/questions/5772629)
    
    When I try to get the owner of the 'aiming component', the UE
    crush without any info. The bad code is
    [here](<https://github.com/randomwangran/cpp/blob/4903f7304a0c02b15983c36c88ffa025a503753a/Unreal/Section04/Source/BattleTank/Private/TankAIController.cpp>)
    
    My question is simple: why UE4 crash (compiled successfuly but
    crash when Play game) without providing any infomation?
    
    In my bad code: I try to access different
    children (ATank and UTankAimingComponent) who share the parent
    (AActor).
    
    This is not accessible, and the compile should complain about the
    wrong useage instead of crashing without any infomation.
    
    Why this happen?
    
    For the details of this issue, following is the analyse of my bad
    code.

2.  Daniel's reply

    Since `GetControlledTank` is a pointer of `UTankAimingComponent`,
    which is derived from ~ATankAIController
    
    This is not correct. UTankAimingComponent is not derived from
    ATankAIController, they are unrelated.
    
    As you can see `Tank` and `UTankAimingComponent` has a same parent
    `AActor`. This is the moment I make a huge mistake: different children
    cannot access each other even they share the parrent.
    
    What do you mean by this? It seems like you're confusing the
    class hierarchy with the actual instances of those classes.
    
    `=================`
    
    ATank* ATankAIController::GetControlledTank() const
    {
        return Cast<ATank>(GetPawn());
    }
    
    UTankAimingComponent\* ATankAIController::GetAimingComponent()
    const { return Cast<UTankAimingComponent>(GetPawn()); } The first
    function is correct the second is not. GetPawn returns a pointer
    to the same object, casting it doesn't magically make it get the
    thing that you're looking for, it just says treat it as if it
    were this type instead. It compiles because the class hierarchy
    you described, APawn and UTankAimingComponent share a common base
    class though this isn't what you want to do.
    
    Consider the following
    
    class AAnimal{};
    class ACat : public AAnimal{ /*code*/ };
    class ADog : public AAnimal{ /*code*/ };
    
    ADog* GetDog();
    
    void DoSomething(AAnimal* Animal)
    {
        ACat* Cat = Cast<ACat>(Animal);
        Cat->Meow();
    }
    
    int main(){ 
        ADog* Dog = GetDog(); 
        DoSomething(Dog); 
    }
    
    The DoSomething function takes an AAnimal but then casts it to
    ACat\*, in main I give it a ADog\* which means the cast will fail
    and attempting to dereference it on the next line after the cast
    will be undefined behaviour (crash in Unreal) because Cat will be
    nullptr since the cast failed.
    
    TankAimingComponent is a protected member of ATank and should
    remain protected, what you're trying to accomplish would mean
    creating a function on ATank that returns the
    TankAimingComponent. Meaning the code you should have by the end
    would be
    
    GetControlledTank()->GetAimingComponent()->AimAt(HitLocation);

3.  my 2nd reply

    Thank you Daniel for helping me though. I am relatively new to cpp
    programming and want to become a better coder using c++. I've
    read your reply and did some further research. Following is some
    thing that I still not very clear.
    
    > Since `GetControlledTank` is a pointer of `UTankAimingComponent`,
    > which is derived from ~ATankAIController
    > 
    > This is not correct. UTankAimingComponent is not derived from
    > ATankAIController, they are unrelated.
    
    Thanks for pointing out my mistake. `UTankAimingComponent` is not
    derived from `ATankAIController`. It is drived from
    `UActorComponent`. Then `-> UObject -> UObjectBaseUtility ->
         UObjectBase`. 
    
    On the other hand, the inheritance hierarchy for `ATank` is:
    
    ATank -> APawn -> AActor -> UObject -> UObjectBaseUtility ->
    UObjectBase
    
    What I wanted to point out in the last post was that
    `UTankAimingComponent` and `ATank` shared the same parent
    according to the inheritance hierarchy. (`UObject`). 
    
    > As you can see `Tank` and `UTankAimingComponent` has a same parent
    > `AActor`. This is the moment I make a huge mistake: different children
    > cannot access each other even they share the parrent.
    > 
    > What do you mean by this? It seems like you're confusing the
    > class hierarchy with the actual instances of those classes.
    
    What I mean was that, at that time, I thought as long as two
    class shared the same parent at some levels in the inheritance
    hierarchy, they could access to each other. Now I know that this
    is wrong! You can not do that. For example, my parents have three
    children. I am one of them. Even I share the same parent as my
    brother, I cannot access my brother' brain, which is his private
    function.
    
    The new issue is: can children class access the public function
    or variables in their parent class? I suspect the answer is yes!
    
    If `void UTankAimingComponent::AimAt(FVector HitLocation)` is
    something like `void UObject::AimAt(FVector HitLocation)` and
    they are public inherit from upper parents till the same parent
    (`UObject`). Then both `Tank` and `UTankAimingComponent` can
    access this `AimAt` function.
    
    > ATank* ATankAIController::GetControlledTank() const
    > {
    >     return Cast<ATank>(GetPawn());
    > }
    > 
    > UTankAimingComponent\* ATankAIController::GetAimingComponent()
    > const { return Cast<UTankAimingComponent>(GetPawn()); } The first
    > function is correct the second is not. GetPawn returns a pointer
    > to the same object, casting it doesn't magically make it get the
    > thing that you're looking for, it just says treat it as if it
    > were this type instead. It compiles because the class hierarchy
    > you described, APawn and UTankAimingComponent share a common base
    > class though this isn't what you want to do.
    
    I am just curious about why 
    
    UTankAimingComponent* ATankAIController::GetAimingComponent() const { 
        return Cast<UTankAimingComponent>(GetPawn()); 
    }
    
    not work, but it works for `ATank*`?
    
    I jump into the source code of `GetPawn()`:
    
    /** Getter for Pawn */
    FORCEINLINE APawn* GetPawn() const { return Pawn; }
    
    The `ATank` is okay because `ATank` is drived from
    `APawn`. `UTankAimingComponent` fails, becasue its base does not
    include `APawn`.
    
    Thanks for pointing out this point. The reason why the compiler
    did not complain was that they share a common base class:
    `UObject`.
    
    When I was writing the code like:
    
    `return Cast<ATank>(GetPawn());`
    
    It is natually to think that `GetPawn()` should find it's Pawn,
    especially when it is a request from a component. Unreal should
    be able to understand my intention. Why they did not implement
    this straigthforward thought? Do I miss something?
    
    > Consider the following
    > 
    > class AAnimal{};
    > class ACat : public AAnimal{ /*code*/ };
    > class ADog : public AAnimal{ /*code*/ };
    > 
    > ADog* GetDog();
    > 
    > void DoSomething(AAnimal* Animal)
    > {
    >     ACat* Cat = Cast<ACat>(Animal);
    >     Cat->Meow();
    > }
    > 
    > int main(){ 
    >     ADog* Dog = GetDog(); 
    >     DoSomething(Dog); 
    > }
    > 
    > The DoSomething function takes an AAnimal but then casts it to
    > ACat\*, in main I give it a ADog\* which means the cast will fail
    > and attempting to dereference it on the next line after the cast
    > will be undefined behaviour (crash in Unreal) because Cat will be
    > nullptr since the cast failed.
    
    Thanks for providing the code snippet. It really helps me to
    understand.
    
    I think `Cast` function you provided here make sense. I just want
    to use your `DoSomething` function to make an another example. In
    reality `DoSomething` is `Speaking`. When `ADog` call
    `DoSoething` or `Speaking`, the program should always return `Wof
         Wof`. If someone new programmer (like me) screw it up by using
    the `Cast` function, the program should immediately stop. If the
    programmer really want to let `ADog` pronounce `Meow Meow`, it is
    the programmer's responsibilty to implement a new virtual
    function in the Base class `AAnimal` called:
    `DogMimicCatSpeaking`. And then use this new function from `ADog`
    to print out the desired behvior, i.e. print out `Meow Meow`.
    
    However, you can see, by adding this new function
    (`DogMimicCatSpeaking`), I polluted the our Base class `AAnimal`,
    which should not deal with making specific sound. This function
    should be implement in the derived class.
    
    For `Cast` in c++, I've learn that: everytime you cast something,
    you have to make sure that it is succeeded. To achieve this:
    
    void DoSomething(AAnimal* Animal)
    {
        ACat* Cat = Cast<ACat>(Animal);
    
        if(Cat) // adding a checker to protect potential crash
    	Cat->Meow();
    }
    
    After playing with `Cast`, I started to wondering which `Cast` is
    used in Unreal?
    
    There are many Cast types in c++:
    
    -   dynamic<sub>cast</sub>
    -   static<sub>cast</sub>
    -   &#x2026; (perheps more)
    
    In the head file `Casts.h`
    
    // Dynamically cast an object type-safely.
    template <typename To, typename From>
    FORCEINLINE To* Cast(From* Src)
    {
        return TCastImpl<From, To>::DoCast(Src);
    }
    #+END_SRC c++
    
    What does it mean? Is ~Cast~ in the following code a dynamic
    casting, which will convert the base-class pointer into
    derived-class pointer?
    
    #+BEGIN_SRC c++
    ATank* ATankAIController::GetControlledTank() const
    {
        return Cast<ATank>(GetPawn());
    }
    
    It seems yes, but why don't we use?
    
    return dynamic_cast<ATank*>(GetPawn());
    
    > TankAimingComponent is a protected member of ATank and should
    > remain protected, what you're trying to accomplish would mean
    > creating a function on ATank that returns the
    > TankAimingComponent. Meaning the code you should have by the end
    > would be
    > 
    > GetControlledTank()->GetAimingComponent()->AimAt(HitLocation);
    
    I use your suggestoin in `TankAIController.cpp` in my commit: <https://github.com/randomwangran/cpp/blob/4903f7304a0c02b15983c36c88ffa025a503753a/Unreal/Section04/Source/BattleTank/Private/TankAIController.cpp>
    
    void ATankAIController::Tick(float DeltaTime)
    {
       Super::Tick(DeltaTime);
       if (GetPlayerTank())
       {
    	   // TODO Move towards the player
    
    	   // Aim towards the player
    	   GetControlledTank()->GetAimingComponent()->AimAt(HitLocation);
       }
    }
    
    But fail to compile:
    
    CompilerResultsLog: Error: ~\\Unreal\Section04\Source\BattleTank\Private\TankAIController.cpp(32) : error C2039: 'GetAimingComponent': is not a member of 'ATank'
    CompilerResultsLog: Error: ~\unreal\section04\source\battletank\public\Tank.h(10) : note: see declaration of 'ATank'
    CompilerResultsLog: Error: ~\\Unreal\Section04\Source\BattleTank\Private\TankAIController.cpp(32) : error C2065: 'HitLocation': undeclared identifier
    CompilerResultsLog: ERROR: UBT ERROR: Failed to produce item: ~\\Unreal\Section04\Binaries\Win64\UE4Editor-BattleTank-685.dll
    
    GetAimingComponent is not a member of `ATank`
    
    My solution is different from Ben's solution: <https://github.com/UnrealCourse/04_BattleTank/blob/54f0adbad057940cb229f4541a727f2383b53e9b/BattleTank/Source/BattleTank/Private/Tank.cpp>
    
    I don't declare in my `Tank.h`:
    
    void ATank::AimAt(FVector HitLocation)
    {
       TankAimingComponent->AimAt(HitLocation);
    }
    
    Because when I accepted his challenge, I think I need to
    completely refactor `AimAt` function in the
    `UTankAimingComponent.h`
    
    I succesfully made it in my commit:
    
    <https://github.com/randomwangran/cpp/commit/b3c8415642f7a2ac0fc0a7a77126ddd45a4ba043>
    
    This is really a long reply, but I've learn a lot of new stuff
    and refesh my mind on old stuff. I hope it is not daunting you.
    
    Ran


<a id="orgfbd0daa"></a>

## a-ha moment


<a id="org2226b6d"></a>

### pointer to pointer

This is the first time that I use it intentionlly in real
programming, and it is in this lesson, that I've learnt that it is
useful when you want to separate a function in a class.

I've stuck in this issue for a long time. At first, I think I
should write another getter to return a 'UTankAimingComponent'
pointer so that the tank can use `AimAt` method defined in
'UTankAimingComponent' class.

UTankAimingComponent* ATankAIController::GetAimingComponent() const
{
    return Cast<UTankAimingComponent>(GetPawn());
}

However, when I call `GetAimingComponent` From class
`TankAIController`, the code compiled, which is the result of
commit `4903f7304a0c02b15983c36c88ffa025a503753a`. But as soon as
I click `Play` button, UE4 crash without any information.

Since `GetControlledTank` is a pointer of `UTankAimingComponent`,
which is derived from `ATankAIController`. And `ATankAIController`
is drived from `AAIController`. Then, `AAIController` is drived
from `AController`. Next, `AController` is drived from
`AActor`. Then, `AActor` is drived from `UObject` is drived from
`UObjectBaseUtility`. Finally `UObjectBaseUtility` is drived from
`UObjectBase`.

The diagram for the `Tank` class is:

<div class="org-center">
ATank &#x2013;> APawn &#x2013;> AActor &#x2013;> &#x2026;
</div>

As you can see `Tank` and `UTankAimingComponent` has a same parent
`AActor`. This is the moment I make a huge mistake: different
children cannot access each other even they share the parrent.

The correct way to do this to using
`GetControlledTank()->TankAimingComponent->AimAt(GetPlayerTank()->GetActorLocation());`
, i.e., the pointer to pointer, which will correct guide the
`Tank` class's instance (AI tanks and Player tank) to use the the
`AimAt` method defined in the separated class `UTankAimingComponent`.


# Google Code Jam 2016

This repository contains my solutions to the problems from [Google Code Jam 2016][1] and [Distributed Google Code Jam 2016][2]. These solutions are provided "as is" - I give no guarantees that they will work as expected.

## Instructions

You can compile all Google Code Jam problems by issuing the following command:

    $ make

If you want to compile only a specific problem, issue the following command, replacing `<problem_id>` with the section and identifier of the problem you want to compile (see section "Problems Solved" for the list of possible identifiers):

    $ make <problem_id>

Running a compiled problem is just a matter of executing a command similar to the next one, replacing `<problem_id>` with the identifier of the desired problem:

    $ ./<problem_id>

Unless stated otherwise, every problem in this repository reads from the standard input and writes to the standard output.

Distributed Google Code Jam problems should be compiled and run using the local testing tool described in the [guide][3]. An example would be:

    $ dcj test --source <round_name>/<problem_id>.cpp --nodes <number_of_nodes>

You'll need to have an input header file with the name `<problem_id>.h` in the same directory as the source file. You can download sample inputs from each problem's page.

## Problems Solved

The following is the list of the problems solved. Each problem identifier is specified between round brackets. Problems marked with ✓ are done, while problems with ✗ are not complete or aren't efficient enough for the problem's limits.

### Qualification Round

* ✓ [A: Counting Sheep][qual1] (`counting-sheep`)
* ✓ [B: Revenge of the Pancakes][qual2] (`revenge-of-the-pancakes`)
* ✓ [C: Coin Jam][qual3] (`coin-jam`)
* ✓ [D: Fractiles][qual4] (`fractiles`)

### Round 1A

* ✓ [A: The Last Word][round1a1] (`the-last-word`)
* ✓ [B: Rank and File][round1a2] (`rank-and-file`)
* ✓ [C: BFFs][round1a3] (`bffs`)

### Round 1B

* ✓ [A: Getting the Digits][round1b1] (`getting-the-digits`)
* ✓ [B: Close Match][round1b2] (`close-match`)
* ✓ [C: Technobabble][round1b3] (`technobabble`)

### Round 1C

* ✓ [A: Senate Evacuation][round1c1] (`senate-evacuation`)
* ✓ [B: Slides!][round1c2] (`slides`)
* ✓ [C: Fashion Police][round1c3] (`fashion-police`)

### Round 2

* ✓ [A: Rather Perplexing Showdown][round21] (`rather-perplexing-showdown`)
* ✗ [B: Red Tape Committtee][round22] (`red-tape-committee`)

### Distributed Round 1

* ✓ [B: Oops][distribround12] (`oops`)
* ✓ [C: Remarkably Parallel Scenario][distribround13] (`rps`)
* ✓ [D: Rearranging Crates][distribround14] (`crates`)
* ✓ [E: Winning Move][distribround15] (`winning_move`)

[1]: https://code.google.com/codejam
[2]: https://code.google.com/codejam/distributed_index.html
[3]: https://code.google.com/codejam/distributed_guide.html
[qual1]: https://code.google.com/codejam/contest/6254486/dashboard#s=p0
[qual2]: https://code.google.com/codejam/contest/6254486/dashboard#s=p1
[qual3]: https://code.google.com/codejam/contest/6254486/dashboard#s=p2
[qual4]: https://code.google.com/codejam/contest/6254486/dashboard#s=p3
[round1a1]: https://code.google.com/codejam/contest/4304486/dashboard#s=p0
[round1a2]: https://code.google.com/codejam/contest/4304486/dashboard#s=p1
[round1a3]: https://code.google.com/codejam/contest/4304486/dashboard#s=p2
[round1b1]: https://code.google.com/codejam/contest/11254486/dashboard#s=p0
[round1b2]: https://code.google.com/codejam/contest/11254486/dashboard#s=p1
[round1b3]: https://code.google.com/codejam/contest/11254486/dashboard#s=p2
[round1c1]: https://code.google.com/codejam/contest/4314486/dashboard#s=p0
[round1c2]: https://code.google.com/codejam/contest/4314486/dashboard#s=p1
[round1c3]: https://code.google.com/codejam/contest/4314486/dashboard#s=p2
[round21]: https://code.google.com/codejam/contest/10224486/dashboard#s=p0
[round22]: https://code.google.com/codejam/contest/10224486/dashboard#s=p1
[distribround12]: https://code.google.com/codejam/contest/11264486/dashboard#s=p1
[distribround13]: https://code.google.com/codejam/contest/11264486/dashboard#s=p2
[distribround14]: https://code.google.com/codejam/contest/11264486/dashboard#s=p3
[distribround15]: https://code.google.com/codejam/contest/11264486/dashboard#s=p4

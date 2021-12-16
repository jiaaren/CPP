### Casts
- Casts and notions

### Types
1. Implicit
2. Explicit

### Conversions and hierarchy between types
- conversions between `ints` and `doubles`
    - `ints` are represented by bits
    - `doubles` represented by sign, mantissa and exponent (scientific notation)
- `doubles` are higher in hierarchy compared to `ints`
    - int -> doubles (promotion) - 
        - implicit casting - **generally ok**
        - explicit casting - ok
    - doubles -> int (demotion)
        - implicit casting - **hazardous**
        - explicit casting - ok

- Implicit usually ok for single instance
    - If called in loops, may not be the best as previous values will be used for current calculations
    - **error margins will become bigger and bigger**
    - precision may be a problem because of information loss

- Currently there are compilation flags to inform implicit casting

- [Reference](https://stackoverflow.com/questions/27998696/is-implicit-casting-considered-to-be-a-bad-concept)
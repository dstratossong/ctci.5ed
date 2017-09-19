**Describe how you could use a single array to implement three stacks.**

We could splice the indices so that the three stacks use indices `3n`, `3n+1`, `3n+2` respectively, where `n` is a non-negative integer. We could expand the array just like we'd expand a single stack, but when we push or pop, we have to update the counter by 3.

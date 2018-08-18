// std::unordered_map

// Associative container that store elements formed by the combination of a key value and
// a mapped value, and which allows for fast retrieval of individual elements based on their keys

// Internally, the elements in the unordered_map are not sorted in any particular order
// but organized into buckets depending on their hash values to allow for fast access to individual
// elements directly by their key values (with a constant average time complexity on average).

// Unordered_maps implement the direct access operator (operator[]) which allows for direct
// access of the mapped value using its key value as argument
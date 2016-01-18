#pragma once

#include <glm/gtc/type_precision.hpp>

#include <glkernel/Kernel.h>
#include <glkernel/glm_compatability.h>


namespace glkernel
{

namespace sample
{

// returns number of actual generated points (note: this number is between 0 and kernel.size)

// guess a good number that targets the actual generated number of points generated to match kernel.size
template <typename T, glm::precision P>
size_t poisson_square(tkernel<glm::tvec2<T, P>> & kernel, unsigned int num_probes = 32);

// in contrast to the typical default impl. this impl uses the best of num_probes, randomizes the actives, ...
template <typename T, glm::precision P>
size_t poisson_square(tkernel<glm::tvec2<T, P>> & kernel, T min_dist, unsigned int num_probes = 32);

/**
*  @brief
*  Generates the hammersley point set
*
*  @param[in,out] kernel
*  The kernel to be modified
*/
template <typename T, glm::precision P>
void hammersley(tkernel<glm::tvec2<T, P>> & kernel);

/**
*  @brief
*  Generates the halton point set
*
*  @param[in,out] kernel
*  The kernel to be modified
*
*  @param[in] base1
*  Base for the "van der Corput" sequence used for the x coordinates
*
*  @param[in] base2
*  Base for the "van der Corput" sequence used for the y coordinates
*/
template <typename T, glm::precision P>
void halton(tkernel<glm::tvec2<T, P>> & kernel, const unsigned int base1, const unsigned int base2);

/**
*  @brief
*  Hemisphere mapping used for hammersley and halton sampling
*/
enum class HemisphereMapping : unsigned char
{
    Uniform,
    Cosine
};

/**
*  @brief
*  Generates the hammersley point set and maps it to a hemisphere
*
*  @param[in,out] kernel
*  The kernel to be modified
*
*  @param[in] type
*  Mapping used for generating points on a sphere
*/
template <typename T, glm::precision P>
void hammersley_sphere(
    tkernel<glm::tvec3<T, P>> & kernel,
    const HemisphereMapping type = HemisphereMapping::Uniform);

/**
*  @brief
*  Generates the halton point set and maps it to a hemisphere
*
*  @param[in,out] kernel
*  The kernel to be modified
*
*  @param[in] type
*  Mapping used for generating points on a sphere
*
*  @param[in] base1
*  Base for the "van der Corput" sequence used for the x coordinates
*
*  @param[in] base2
*  Base for the "van der Corput" sequence used for the y coordinates
*/
template <typename T, glm::precision P>
void halton_sphere(
    tkernel<glm::tvec3<T, P>> & kernel,
    const unsigned int base1,
    const unsigned int base2,
    const HemisphereMapping type = HemisphereMapping::Uniform);
/*
*  @brief
*  Generates several candidates for each samples and selects the one
*  that is farthest to the previously selected samples
*
*  @param[in,out] kernel
*  The kernel to be modified
*
*  @param[in] num_candidates
*  Number of candidates generated for each sample
*/
template <typename T, glm::precision P>
void best_candidate(tkernel<glm::tvec2<T, P>> & kernel, unsigned int num_candidates = 32);

} // namespace sample

} // namespace glkernel

#include <glkernel/sample.hpp>

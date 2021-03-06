/*
 * Copyright (C) 2006-2020  Music Technology Group - Universitat Pompeu Fabra
 *
 * This file is part of Essentia
 *
 * Essentia is free software: you can redistribute it and/or modify it under
 * the terms of the GNU Affero General Public License as published by the Free
 * Software Foundation (FSF), either version 3 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the Affero GNU General Public License
 * version 3 along with this program.  If not, see http://www.gnu.org/licenses/
 */

#ifndef __EXTRACTOR_EXAMPLE_H__   
#define __EXTRACTOR_EXAMPLE_H__ 

#include <vector>
#include <essentia/algorithmfactory.h>
#include <essentia/essentiamath.h>
#include <emscripten/bind.h>

using namespace essentia;
using namespace essentia::standard;
using namespace emscripten;


class LogMelSpectrogramExtractor {

  public:
    std::string essentiaVersion = essentia::version;

    LogMelSpectrogramExtractor(const int frameSize=1024, const int hopSize=512, const int numBands=96, const std::string& windowType="hann");

    ~LogMelSpectrogramExtractor() {};

    void configure(const int frameSize=1024, const int hopSize=512, const int numBands=96, const std::string& windowType="hann");

    std::vector<float> compute(const val& audioData);

    void reset();

    void shutdown();

  private:
    Algorithm* _frameCut;
    Algorithm* _window;
    Algorithm* _spect;
    Algorithm* _melBand;
    Algorithm* _logNorm;

};

// convert a Float32 JS typed array into std::vector<float>
// https://github.com/emscripten-core/emscripten/issues/5519#issuecomment-589702756
std::vector<float> float32ArrayToVector(const val &v); 

#endif // __EXTRACTOR_EXAMPLE_H__
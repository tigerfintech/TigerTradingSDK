//
// Copyright 2009-2011 Facebook
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

/**
 * These flags are used primarily by TBKDEBUGCONDITIONLOG.
 * Example:
 *
 *    TBKDEBUGCONDITIONLOG(TBKDEBUGFLAGNAVIGATOR, @"TBKNavigator activated");
 *
 * This will only write to the log if the TBKDEBUGFLAGNAVIGATOR is set to non-zero.
 */
#define TBKDEBUGFLAGVIEWCONTROLLERS             0
#define TBKDEBUGFLAGCONTROLLERGARBAGECOLLECTION 0
#define TBKDEBUGFLAGNAVIGATOR                   0
#define TBKDEBUGFLAGTABLEVIEWMODIFICATIONS      0
#define TBKDEBUGFLAGLAUNCHERVIEW                0
#define TBKDEBUGFLAGURLREQUEST                  0
#define TBKDEBUGFLAGURLCACHE                    0
#define TBKDEBUGFLAGXMLPARSER                   0
#define TBKDEBUGFLAGETAGS                       0

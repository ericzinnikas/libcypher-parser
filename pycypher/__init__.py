# Copyright 2017, Google Inc. All rights reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

from .bindings import parse_query as inner_parse_query
from .ast import CypherAstNode
from .version import __version__


__ALL__ = ['parse_query', 'CypherAstNode', 'CypherParseError']


class CypherParseError(Exception):
    def __init__(self, message, context, offset, context_offset):
        super(CypherParseError, self).__init__(message)
        self.message = message
        self.context = context
        self.offset = offset
        self.context_offset = context_offset
        self.all_errors = None
        self.parse_result = None


def parse_query(query):
    result, errors = inner_parse_query(CypherAstNode, CypherParseError, query)
    if errors:
        e = errors[0]
        e.all_errors = errors
        e.parse_result = result
        raise e
    else:
        return result

[@ocaml.ppx.context
  {
    tool_name: "migrate_driver",
    include_dirs: [],
    load_path: [],
    open_modules: [],
    for_package: None,
    debug: false,
    use_threads: false,
    use_vmthreads: false,
    recursive_types: false,
    principal: false,
    transparent_modules: false,
    unboxed_types: false,
    unsafe_string: false,
    cookies: [],
  }
];
module MyQuery = {
  module Raw = {
    type t = {. "optionalInputArgs": string};
  };
  let query = "mutation MyMutation($required: String!)  {\noptionalInputArgs(required: $required, anotherRequired: \"val\")  \n}\n";
  type t = {. "optionalInputArgs": string};
  type t_variables = {. "required": string};
  let parse: Raw.t => t =
    value => {

      "optionalInputArgs": {
        let value = value##optionalInputArgs;

        value;
      },
    };
  let serialize: t => Raw.t =
    value => {

      "optionalInputArgs": {
        let value = value##optionalInputArgs;

        value;
      },
    };
  let serializeVariables: t_variables => Js.Json.t =
    inp =>
      [|("required", (a => Some(Js.Json.string(a)))(inp##required))|]
      |> Js.Array.filter(
           fun
           | (_, None) => false
           | (_, Some(_)) => true,
         )
      |> Js.Array.map(
           fun
           | (k, Some(v)) => (k, v)
           | (k, None) => (k, Js.Json.null),
         )
      |> Js.Dict.fromArray
      |> Js.Json.object_;
  let makeVar = (~f, ~required, ()) =>
    f(
      serializeVariables(
        {

          "required": required,
        }: t_variables,
      ),
    );
  let make =
    makeVar(~f=variables =>
      {"query": query, "variables": variables, "parse": parse}
    );
  let makeWithVariables = variables => {
    "query": query,
    "variables": serializeVariables(variables),
    "parse": parse,
  };
  let definition = (parse, query, makeVar);
  let makeVariables = makeVar(~f=f => f);
};

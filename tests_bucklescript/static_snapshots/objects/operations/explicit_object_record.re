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
module RecordsQuery = {
  module Raw = {
    type t = {lists: t_lists}
    and t_lists = {
      nullableOfNullable: Js.Nullable.t(array(Js.Nullable.t(string))),
      nullableOfNonNullable: Js.Nullable.t(array(string)),
      nonNullableOfNullable: array(Js.Nullable.t(string)),
      nonNullableOfNonNullable: array(string),
    };
  };
  let query = "query   {\nlists  {\nnullableOfNullable  \nnullableOfNonNullable  \nnonNullableOfNullable  \nnonNullableOfNonNullable  \n}\n\n}\n";
  type t = {lists: t_lists}
  and t_lists = {
    nullableOfNullable: option(array(option(string))),
    nullableOfNonNullable: option(array(string)),
    nonNullableOfNullable: array(option(string)),
    nonNullableOfNonNullable: array(string),
  };
  let parse: Raw.t => t =
    (value) => (
      {

        lists: {
          let value = (value: Raw.t).lists;
          (
            {

              nullableOfNullable: {
                let value = (value: Raw.t_lists).nullableOfNullable;

                switch (Js.toOption(value)) {
                | Some(value) =>
                  Some(
                    value
                    |> Js.Array.map(value =>
                         switch (Js.toOption(value)) {
                         | Some(value) => Some(value)
                         | None => None
                         }
                       ),
                  )
                | None => None
                };
              },

              nullableOfNonNullable: {
                let value = (value: Raw.t_lists).nullableOfNonNullable;

                switch (Js.toOption(value)) {
                | Some(value) => Some(value |> Js.Array.map(value => value))
                | None => None
                };
              },

              nonNullableOfNullable: {
                let value = (value: Raw.t_lists).nonNullableOfNullable;

                value
                |> Js.Array.map(value =>
                     switch (Js.toOption(value)) {
                     | Some(value) => Some(value)
                     | None => None
                     }
                   );
              },

              nonNullableOfNonNullable: {
                let value = (value: Raw.t_lists).nonNullableOfNonNullable;

                value |> Js.Array.map(value => value);
              },
            }: t_lists
          );
        },
      }: t
    );
  let serialize: t => Raw.t =
    (value) => (
      {

        lists: {
          let value = (value: t).lists;
          (
            {

              nullableOfNullable: {
                let value = (value: t_lists).nullableOfNullable;

                switch (value) {
                | Some(value) =>
                  Js.Nullable.return(
                    generate_serializer(config, path, definition, inner),
                  )
                | None => Js.Nullable.null
                };
              },

              nullableOfNonNullable: {
                let value = (value: t_lists).nullableOfNonNullable;

                switch (value) {
                | Some(value) =>
                  Js.Nullable.return(
                    generate_serializer(config, path, definition, inner),
                  )
                | None => Js.Nullable.null
                };
              },

              nonNullableOfNullable: {
                let value = (value: t_lists).nonNullableOfNullable;

                value
                |> Js.Array.map(value =>
                     switch (value) {
                     | Some(value) =>
                       Js.Nullable.return(
                         generate_serializer(config, path, definition, inner),
                       )
                     | None => Js.Nullable.null
                     }
                   );
              },

              nonNullableOfNonNullable: {
                let value = (value: t_lists).nonNullableOfNonNullable;

                value |> Js.Array.map(value => value);
              },
            }: Raw.tt_lists
          );
        },
      }: Raw.tt
    );
  let makeVar = (~f, ()) => f(Js.Json.null);
  let definition = (parse, query, makeVar);
};

module ObjectsQuery = {
  module Raw = {
    type t = {. "lists": t_lists}
    and t_lists = {
      .
      "nullableOfNullable": Js.Nullable.t(array(Js.Nullable.t(string))),
      "nullableOfNonNullable": Js.Nullable.t(array(string)),
      "nonNullableOfNullable": array(Js.Nullable.t(string)),
      "nonNullableOfNonNullable": array(string),
    };
  };
  let query = "query   {\nlists  {\nnullableOfNullable  \nnullableOfNonNullable  \nnonNullableOfNullable  \nnonNullableOfNonNullable  \n}\n\n}\n";
  type t = {. "lists": t_lists}
  and t_lists = {
    .
    "nullableOfNullable": option(array(option(string))),
    "nullableOfNonNullable": option(array(string)),
    "nonNullableOfNullable": array(option(string)),
    "nonNullableOfNonNullable": array(string),
  };
  let parse: Raw.t => t =
    value => {

      "lists": {
        let value = value##lists;
        {

          "nullableOfNullable": {
            let value = value##nullableOfNullable;

            switch (Js.toOption(value)) {
            | Some(value) =>
              Some(
                value
                |> Js.Array.map(value =>
                     switch (Js.toOption(value)) {
                     | Some(value) => Some(value)
                     | None => None
                     }
                   ),
              )
            | None => None
            };
          },

          "nullableOfNonNullable": {
            let value = value##nullableOfNonNullable;

            switch (Js.toOption(value)) {
            | Some(value) => Some(value |> Js.Array.map(value => value))
            | None => None
            };
          },

          "nonNullableOfNullable": {
            let value = value##nonNullableOfNullable;

            value
            |> Js.Array.map(value =>
                 switch (Js.toOption(value)) {
                 | Some(value) => Some(value)
                 | None => None
                 }
               );
          },

          "nonNullableOfNonNullable": {
            let value = value##nonNullableOfNonNullable;

            value |> Js.Array.map(value => value);
          },
        };
      },
    };
  let serialize: t => Raw.t =
    value => {

      "lists": {
        let value = value##lists;
        {

          "nullableOfNullable": {
            let value = value##nullableOfNullable;

            switch (value) {
            | Some(value) =>
              Js.Nullable.return(
                generate_serializer(config, path, definition, inner),
              )
            | None => Js.Nullable.null
            };
          },

          "nullableOfNonNullable": {
            let value = value##nullableOfNonNullable;

            switch (value) {
            | Some(value) =>
              Js.Nullable.return(
                generate_serializer(config, path, definition, inner),
              )
            | None => Js.Nullable.null
            };
          },

          "nonNullableOfNullable": {
            let value = value##nonNullableOfNullable;

            value
            |> Js.Array.map(value =>
                 switch (value) {
                 | Some(value) =>
                   Js.Nullable.return(
                     generate_serializer(config, path, definition, inner),
                   )
                 | None => Js.Nullable.null
                 }
               );
          },

          "nonNullableOfNonNullable": {
            let value = value##nonNullableOfNonNullable;

            value |> Js.Array.map(value => value);
          },
        };
      },
    };
  let makeVar = (~f, ()) => f(Js.Json.null);
  let definition = (parse, query, makeVar);
};